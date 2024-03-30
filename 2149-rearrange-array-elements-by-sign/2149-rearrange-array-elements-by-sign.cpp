class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int positiveNoInd = 0;
        int negativeNoInd = 1;
        vector<int>ans(nums.size());
        for(int val : nums){
            if(val > 0){
                ans[positiveNoInd] = val;
                positiveNoInd += 2;
            }
            else{
                ans[negativeNoInd] = val;
                negativeNoInd +=2;
            }
        }
        return ans;
    }
}; 