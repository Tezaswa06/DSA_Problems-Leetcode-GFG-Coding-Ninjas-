class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans(nums.size(),pivot);
        int left = 0;
        int right = ans.size()-1;
        // int index = ans.size()-1;
        for(int idx = nums.size()-1; idx >=0; idx--)
        {
            if(nums[idx] > pivot)
            {
                ans[right] = nums[idx];
                right--;
            }
        }
        // int left = 0;
        for(int val : nums)
        {
            if(val < pivot)
            {
                ans[left] = val;
                left++;
            }
        }
        return ans;
    }
};