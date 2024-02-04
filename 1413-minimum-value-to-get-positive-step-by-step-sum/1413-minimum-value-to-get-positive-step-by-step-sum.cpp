class Solution {
public:
    int minStartValue(vector<int>& nums) {
        
        int startvalue = 1;
        int sum = 1;
        
        for(int num : nums){
            sum+=num;
            if(sum<=0){
                startvalue += 1-sum;
                sum = 1;
            }
        }
        return startvalue;
    }
};