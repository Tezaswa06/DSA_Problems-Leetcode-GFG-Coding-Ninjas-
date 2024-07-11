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
//     bool canJump(vector<int>& jumps) {
//         vector<long>dp(jumps.size() + 1,-1);
//         return memoization(0,jumps,dp) == INT_MAX ? false : true;
//     }
// };

class Solution {
public:
    bool canJump(vector<int>& jumps) {
        int reach = 0;
        for(int i=0; i<jumps.size(); i++){
            if(i > reach){
                return false;
            }
            if(i + jumps[i] > reach){
                reach = i + jumps[i];
            }
        }
        return true;
    }
};