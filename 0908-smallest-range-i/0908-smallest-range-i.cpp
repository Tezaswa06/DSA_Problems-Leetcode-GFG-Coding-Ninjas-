class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int maxval = nums[0];
        int minval = nums[0];

        for(int val : nums)
        {
            minval = min(minval,val);
            maxval = max(maxval,val);
        }

        if(minval +k >= maxval -k)
        {
            return 0;
        }
        else
        {
            return (maxval -k) - (minval+k);
        }
    }
};