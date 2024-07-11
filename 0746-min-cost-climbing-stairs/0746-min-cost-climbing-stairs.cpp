// memoization

// class Solution {
// public:
//     int memoization(int src,vector<int>& cost,vector<int>& dp){
//         if(src >= cost.size()){
//             return 0;
//         }
//         if(dp[src] != -1){
//             return dp[src];
//         }
//         int ans1 = memoization(src + 1,cost,dp);
//         int ans2 = memoization(src + 2,cost,dp);

//         dp[src] = min(ans1,ans2) + cost[src];
//         return dp[src];
//     }
    
//     int minCostClimbingStairs(vector<int>& cost) {
//         vector<int>dp(cost.size() + 1,-1);
//         memoization(0,cost,dp);
//         return min(dp[0],dp[1]);
//     }
// };

// tabulation

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size(),-1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i=2; i<cost.size(); i++){
            dp[i] = min(dp[i-1],dp[i-2]) + cost[i];
        }
        return min(dp[cost.size() - 1],dp[cost.size() - 2]);
    }
};