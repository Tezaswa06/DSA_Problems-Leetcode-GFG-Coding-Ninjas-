// Recursion

// class Solution {
// public:
//     int fib(int n) {
//         if(n == 0){
//             return 0;
//         }
//         if(n == 1){
//             return 1;
//         }

//         int prev1 = fib(n - 1);
//         int prev2 = fib(n - 2);
//         int curr = prev1 + prev2;

//         return curr;
//     }
// };

// memoization

// class Solution {
// public:
//     int fibonacci(int n, vector<int>& dp){
//         if(n == 0){
//             return 0;
//         }
//         if(n == 1){
//             return 1;
//         }

//         if(dp[n] != -1){
//             return dp[n];
//         }
//         int prev1 = fibonacci(n-1,dp);
//         int prev2 = fibonacci(n-2,dp);
//         dp[n] = prev1 + prev2;// before returning from the calclulated value store it somewhere
//         return prev1 + prev2;
//     }
//     int fib(int n) {
//         vector<int>dp(n+1,-1);
//         return fibonacci(n,dp);
//     }
// };

// tabulation

// class Solution {
// public:
//     int fib(int n) {
//         if(n == 0){
//             return 0;
//         }

//         vector<int>dp(n + 1);
//         dp[0] = 0;
//         dp[1] = 1;
//         for(int i=2; i<=n; i++){
//             dp[i] = dp[i-1] + dp[i-2];
//         }
//         return dp[n];
//     }
// };

class Solution {
public:
    int fib(int n) {
        if(n <= 1){
            return n;
        }
        int prev1 = 0;
        int prev2 = 1;

        for(int i=2; i<=n; i++){
            int curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
};