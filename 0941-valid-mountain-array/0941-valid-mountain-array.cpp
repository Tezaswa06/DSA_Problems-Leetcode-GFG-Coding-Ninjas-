class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3){
            return false;
        }
        int index = 0;
        while(index+1<arr.size()){
            if(arr[index]==arr[index+1]){
                return false;
            }
            else if(arr[index]>arr[index+1]){
                break;
            }
            index++;
        }
        if(index==0){
            return false;
        }
        if(index==arr.size()-1){
            return false;
        }
        
        while(index+1<arr.size()){
            if(arr[index]==arr[index+1]){
                return false;
            }
            else if(arr[index]<arr[index+1]){
                break;
            }
            index++;
        }
        return (index == arr.size()-1);
    }
};