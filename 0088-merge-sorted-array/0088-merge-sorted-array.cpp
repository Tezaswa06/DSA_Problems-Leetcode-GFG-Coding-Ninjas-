class Solution {
public:
    void merge(vector<int>& nums1, int n1, vector<int>& nums2, int n2) {
        int p1 = n1 - 1;
        int p2 = n2 - 1;
        int p3 = n1 + n2 - 1;

        while(p1 >= 0 && p2 >= 0){
            if(nums1[p1] > nums2[p2]){ // we are checking from the last index of both the input array and after comparison we are storing it in the first array 
                nums1[p3] = nums1[p1];
                p3--;
                p1--;
            }
            else{
                nums1[p3] = nums2[p2];
                p3--;
                p2--;
            }
        }
        while(p1 >= 0){
            nums1[p3] = nums1[p1];
            p3--;
            p1--;
        }
        while(p2 >= 0){
            nums1[p3] = nums2[p2];
            p3--;
            p2--;
        }
    }
};