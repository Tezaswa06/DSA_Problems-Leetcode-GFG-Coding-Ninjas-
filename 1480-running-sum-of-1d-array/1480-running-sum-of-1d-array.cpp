class Solution {
public:
// the below code contains inplace ans outplace both methods
    vector<int> runningSum(vector<int>& nums) {
        vector<int>prefSum(nums.size(),0);
        // prefSum[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            //prefSum[i] = prefSum[i-1] + nums[i];
            nums[i] = nums[i-1] + nums[i];
        }
        // return prefSum;
        return nums;
    }
};