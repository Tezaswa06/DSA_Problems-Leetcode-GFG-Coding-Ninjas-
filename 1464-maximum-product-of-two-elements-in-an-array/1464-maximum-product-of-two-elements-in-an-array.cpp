class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int firstmax = INT_MIN;
        int secondmax = INT_MIN;
        int firstmin = INT_MAX;
        int secondmin = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(firstmax<=nums[i]){
                secondmax = firstmax;
                firstmax = nums[i];
            }
            else if(nums[i]>secondmax){
                secondmax = nums[i];
            }
            if(firstmin>=nums[i]){
                secondmin = firstmin;
                firstmin = nums[i];
            }
            else if(secondmin>nums[i]){
                secondmin = nums[i];
            }
        }
        int choice1 = (firstmin-1) * (secondmin-1);
        int choice2 = (firstmax-1) * (secondmax-1);
        return max(choice1,choice2);
    }
};