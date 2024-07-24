class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int>suffArr(n);
        suffArr[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            suffArr[i] = max(suffArr[i+1],nums[i]);
        }
        int i=0;
        int j=0; 
        int ans = 0;
        while(i < n && j < n){
            if(nums[i] <= suffArr[j]){
                ans = max(ans,j - i);
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};