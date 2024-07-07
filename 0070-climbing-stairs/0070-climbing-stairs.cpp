// recursive sol will give tle

// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n == 0){
//             return 1;
//         }
//         if(n < 0){
//             return 0;
//         }

//         int ans1 = climbStairs(n-1);
//         int ans2 = climbStairs(n-2);
//         return ans1 + ans2;
//     }
// };

// Memoization

class Solution {
public:
    int memoization(int n,vector<int>& dp){
        if(n == 0){
            return 1;
        }
        if(n < 0){
            return 0;
        }
        if(dp[n] != -1){//checking the dp array if we got ans or not and if got then return right away
            return dp[n];
        }

        int ans1 = memoization(n-1,dp);
        int ans2 = memoization(n-2,dp);

        dp[n] = ans1 + ans2;
        return dp[n];
    }
    int tabulation(int n,vector<int>& dp){
        dp[0] = 1;
        for(int i=1; i<=n; i++){
            int ans1 = (i - 1) >= 0 ? dp[i-1] : 0;
            int ans2 = (i - 2) >= 0 ? dp[i-2] : 0;
            dp[i] = ans1 + ans2;
        } 
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n + 1);
        return tabulation(n,dp);
    }
};