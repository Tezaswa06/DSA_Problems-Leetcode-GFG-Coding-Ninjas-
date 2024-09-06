// Approach 1

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int maximum = prices[n-1];
//         int profit = 0;

//         for(int right=n-1; right>=0; right--){
//             maximum = max(maximum,prices[right]);
//             profit = max(profit,maximum - prices[right]);
//         }
//         return profit;
//     }
// };

// Approach 2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = prices[0];
        int profit = 0;
        for(int left=0; left<prices.size(); left++){
            minimum = min(minimum,prices[left]);
            profit = max(profit,prices[left]-minimum);
        }
        return profit;
    }
};