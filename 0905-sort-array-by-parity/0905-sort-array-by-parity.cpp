class Solution {
public:
    void swap(vector<int>& nums,int left,int right){
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
    }
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;
        int right = 0;

        while(right < nums.size()){
            if(nums[right] %2 == 0){
                swap(nums,left,right);
                left++;
                right++;
            }
            else{
                right++;
            }
        }
        return nums;
    }
};