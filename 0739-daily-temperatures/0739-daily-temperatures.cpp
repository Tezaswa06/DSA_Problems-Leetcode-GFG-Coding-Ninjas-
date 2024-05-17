class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>stk;
        vector<int>res(temperatures.size());

        for(int idx = temperatures.size()-1; idx >= 0; idx--){
            while(stk.size() > 0 && temperatures[stk.top()] <= temperatures[idx]){
                stk.pop();
            }
            res[idx] = (stk.size() > 0) ? stk.top() - idx : 0;
            stk.push(idx);
        }
        return res;
    }
};