class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        //corner case : if array is already sorted then arr[left]=min and arr[right]=max
        if(nums[left] <= nums[right]){
            return 0;
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
        return left;
    }
    int binarySearch(vector<int>& nums,int target,int low,int high){

        while(low<=high){
            int mid = low + (high - low)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        
        int TransitionPoint = findMin(nums);
        if(TransitionPoint==0){
            return binarySearch(nums,target,0,nums.size()-1);
        }
        if(target<nums[0]){
            return binarySearch(nums,target,TransitionPoint,nums.size()-1);
        }
        else{
            return binarySearch(nums,target,0,TransitionPoint-1);
        }
    
    }
};