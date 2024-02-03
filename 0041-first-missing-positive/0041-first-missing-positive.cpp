class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // discarding the no which are out of range as we want only the first positive nos
        for(int i=0;i<n;i++){
            if(nums[i]<0 || nums[i]>n){
                nums[i] = 0;
            }
        }
        // visited mark adding (n+1) int 1 based indexing
        for(int i=0;i<n;i++){
            int originalnumber = nums[i] % (n+1);
            if(originalnumber > 0){
                nums[originalnumber-1] += (n+1);
            }
        }
        // finding the smallest misssing positive no
        for(int i=0;i<n;i++){
            int frequencycount = nums[i]/(n+1);
            if(frequencycount == 0){
                return i+1;
            }
        }
        return n+1;

    }
};