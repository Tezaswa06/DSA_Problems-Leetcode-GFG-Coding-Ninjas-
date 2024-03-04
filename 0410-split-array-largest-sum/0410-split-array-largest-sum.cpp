class Solution {
public:
    bool ispossible(vector<int>& books,int allowedStud,int maxLoad){
        int currLoad = 0;
        int requiredStud = 1;
        for(int pages : books){
            if(pages > maxLoad){
                return false;
            }
            if(currLoad + pages <= maxLoad){
                currLoad += pages;
            }
            else{
                currLoad = pages;
                requiredStud++;
            }
        }
        return (requiredStud <= allowedStud);
    }
    int splitArray(vector<int>& books, int students) {
        long left = 0;
        long right = pow(10,11);
        
        while(left <= right){
            long mid = left + (right - left)/2;
            
            if(ispossible(books,students,mid)==true){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    
    }
};