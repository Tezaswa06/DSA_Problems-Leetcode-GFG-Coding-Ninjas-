class Solution {
public:
    bool ispossible(vector<int>& weights,int allowedDays,int maxweight){
        int currweight = 0;
        int requiredDays = 1;

        for(int weight : weights){
            // if(weight > maxweight){
            //     return false;
            // }
            if(currweight + weight <= maxweight){
                currweight += weight;
            }
            else{
                currweight = weight;
                requiredDays++;
            }
        }
        return (requiredDays <= allowedDays);
    }
    int max(vector<int>& weights){
        int ans = INT_MIN;
        for(int weight : weights){
            ans = std::max(weight,ans);
        }
        return ans;
    }
    int sum(vector<int>& weights){
        int ans = 0;
        for(int weight : weights){
            ans += weight;
        }
        return ans;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        long left = max(weights);
        long right = sum(weights);
        // long left = 0;
        // long right = pow(10,5);
        while(left <= right){
            long mid = left + (right - left)/2;
            if(ispossible(weights,days,mid)==true){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};