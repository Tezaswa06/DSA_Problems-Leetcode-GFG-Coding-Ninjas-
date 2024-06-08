class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        if(nums.size() == 0){
            return 0;
        }

        int left = 0;
        int maxlen = 1;
        int count = 1; // maintaining counter for duplicate elements
        while(left < nums.size()){
            int right = left + 1;
            int count = 1;
            while(right < nums.size() && nums[right] <= nums[right - 1] + 1){ // agar duplicate element mile to count nhi badhega sirf right badhega
                if(nums[right] == nums[right - 1] + 1){ //  agar 1 se bada 2 mile to hi count ko badhana hai
                    count++;
                }
                right++;
            }
            maxlen = max(maxlen,count);
            left = right;
        }
        return maxlen;
    }
};