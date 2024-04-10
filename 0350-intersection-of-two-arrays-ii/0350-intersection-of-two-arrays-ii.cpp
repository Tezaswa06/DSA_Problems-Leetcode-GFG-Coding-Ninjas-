class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int p1 = 0;
        int p2 = 0;

        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> nums3;
        while(p1 < n1 && p2 < n2){
            if(nums1[p1] < nums2[p2]){
                p1++;
            }
            else if(nums1[p1] > nums2[p2]){
                p2++;
            }
            else{
                nums3.push_back(nums1[p1]);
                p1++;
                p2++;
            }
        }
        return nums3;
    }
};