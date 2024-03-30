class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int evenIndex = 0;
        int oddIndex = 1;
        vector<int>ans(nums.size());
        for(int val : nums){
            if(val % 2 == 0){
                ans[evenIndex] = val;
                evenIndex += 2;
            }
            else{
                ans[oddIndex] = val;
                oddIndex += 2;
            }
        }
        return ans;
    }
};