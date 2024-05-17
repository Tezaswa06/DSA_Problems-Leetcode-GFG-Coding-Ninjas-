class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>nge(n,-1);
        stack<int>stk;

        for(int idx = 0; idx < n; idx++){
            while(stk.size() > 0 && nums[stk.top()] < nums[idx]){
                nge[stk.top()] = nums[idx];
                stk.pop();
            }
            stk.push(idx);
        }
        
        for(int idx = 0; idx < n; idx++){
            while(stk.size() > 0 && nums[stk.top()] < nums[idx]){
                nge[stk.top()] = nums[idx];
                stk.pop();
            }
        }
        return nge;
    }
};