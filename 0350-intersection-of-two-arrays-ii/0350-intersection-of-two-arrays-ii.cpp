class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>freq;

        for(int i=0; i<nums1.size(); i++){
            freq[nums1[i]]++;
        }

        vector<int>intersect;

        for(int j=0; j<nums2.size(); j++){
            if(freq.find(nums2[j]) != freq.end() && freq[nums2[j]] > 0){
                intersect.push_back(nums2[j]);
                freq[nums2[j]]--;
            }
        }
        return intersect;
    }
};