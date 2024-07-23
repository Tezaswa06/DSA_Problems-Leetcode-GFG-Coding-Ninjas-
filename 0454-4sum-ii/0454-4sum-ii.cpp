class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int>AB;

        for(int val1 : nums1){
            for(int val2 : nums2){
                AB[val1 + val2] += 1;
            }
        }

        int count = 0;
        for(int val3 : nums3) {
            for(int val4 : nums4) {
                count += AB[-val3 - val4];
            }
        }
        return count;
    }
};