class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int prefSum = 0;
        freq[0] = 1;

        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefSum += nums[i];
            res += freq[prefSum - k];
            freq[prefSum]++;
        }
        return res;
    }
};