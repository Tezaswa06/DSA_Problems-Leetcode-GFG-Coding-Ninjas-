// memoization

// class Solution {
// public:
//     long memoization(int src,vector<int>& jumps,vector<long>& dp){
//         if(src == jumps.size() - 1){
//             return 0;
//         }
//         if(dp[src] != -1){
//             return dp[src];
//         }
//         long minimum = INT_MAX;
//         for(int jump=1; jump<=jumps[src]; jump++){
//             if(src + jump < jumps.size()){
//                 minimum = min(minimum,memoization(src + jump,jumps,dp) + 1);
//             }
//         }
//         dp[src] = minimum;
//         return minimum;
//     }
//     int jump(vector<int>& jumps) {
//         vector<long>dp(jumps.size() + 1,-1);
//         return memoization(0,jumps,dp);
//     }
// };

// tabulation

class Solution {
public:
    int jump(vector<int>& jumps) {
        int n = jumps.size();

        vector<long>dp(n + 1,INT_MAX);
        dp[n-1] = 0;// No jumps needed to reach the end from the last position

        for(int i=n-2; i>=0; i--){
            for(int jump=1; jump<=jumps[i]; jump++){
                if(jump + i < n){
                    dp[i] = min(dp[i],dp[i + jump] + 1);
                }
            }
        }
        return dp[0];
    }
};