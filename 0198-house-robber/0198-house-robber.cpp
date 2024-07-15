// in the below code prev tells whether that values of nums is taken or not

// class Solution {
// public:
//     int memo(vector<int>& nums,int idx,int prev,vector<vector<int>>& dp){
//         if(idx == nums.size()){
//             return 0;
//         }
//         if(dp[idx][prev] != -1){
//             return dp[idx][prev];
//         }
//         int yes = (prev == 0) ? memo(nums,idx+1,1,dp) + nums[idx] : 0;
//         int no = memo(nums,idx+1,0,dp);

//         return dp[idx][prev] = max(yes,no);
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>>dp(n+1,vector<int>(2,-1));
//         return memo(nums,0,0,dp);
//     }
// };

// tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return nums[0];
        }

        vector<int>dp(n+1,0);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2; i<n; i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};