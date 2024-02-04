class Solution {
public:
    vector<int> prefixsum(vector<int>&nums){
        vector<int>prefixsumarr(nums.size(),0);
        prefixsumarr[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            prefixsumarr[i] = nums[i] + prefixsumarr[i-1];
        }
        return prefixsumarr;
    }
    vector<int> suffixsum(vector<int>&nums){
        vector<int>suffixsumarr(nums.size(),0);
        int n = nums.size();
        suffixsumarr[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffixsumarr[i] = nums[i] + suffixsumarr[i+1];
        }
        return suffixsumarr;
    }
    int pivotIndex(vector<int>& nums) {
        vector<int> leftsum  = prefixsum(nums);
        vector<int> rightsum = suffixsum(nums);
        for(int i=0;i<nums.size();i++){
            if(leftsum[i] == rightsum[i]){
                return i;
            }
        }
        return -1;
    }
};