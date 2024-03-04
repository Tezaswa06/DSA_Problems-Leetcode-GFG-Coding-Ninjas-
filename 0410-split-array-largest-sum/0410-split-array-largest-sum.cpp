class Solution {
public:
    bool ispossiblesplit(vector<int>& nums,int allowedsplits,int maxsum){
        int currsum = 0;
        int requiredsplit = 1;
        for(int val : nums){
            if(currsum + val <= maxsum){
                currsum += val;
            }
            else{
                currsum = val;
                requiredsplit++;
            }
        }
        return (requiredsplit <= allowedsplits);
    }
    long sum(vector<int>& nums){
        int ans = 0;
        for(int val : nums){
            ans += val;
        }
        return ans;
    }
    long max(vector<int>& nums){
        int ans = INT_MIN;
        for(int val : nums){
            ans = std::max(ans,val);
        }
        return ans;
    }
    int splitArray(vector<int>& nums, int splits) {
        long left = max(nums);
        long right = sum(nums);
        
        while(left<=right){
            long mid = left + (right - left)/2;
            if(ispossiblesplit(nums,splits,mid)==true){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};