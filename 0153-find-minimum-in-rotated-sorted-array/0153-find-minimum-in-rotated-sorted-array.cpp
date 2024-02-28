class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        //corner case : if array is already sorted then arr[left]=min and arr[right]=max
        if(nums[left] <= nums[right]){
            return nums[0];
        }
        while(left <= right){
            int mid = left + (right - left)/2;

            // greater region unrortated
            if(nums[mid] >= nums[0]){
                left = mid + 1;
            }
            // lesser region (rotated)
            else{
                right = mid - 1;
            }
        }
        return nums[left];
    }
};