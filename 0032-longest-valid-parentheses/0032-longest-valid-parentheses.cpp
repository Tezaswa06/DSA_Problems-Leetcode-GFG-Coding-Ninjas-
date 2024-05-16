class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int>res(s.size()); // integer array which stores the longes valid parenthesis

        stack<int>stk;
        int maxi = 0;
        for(int idx = 0 ; idx < s.size() ; idx++){
            if(s[idx] == '('){
                stk.push(idx);
            }
            else{
                if(stk.size() == 0){
                    continue;
                }
                int open = stk.top();
                stk.pop();
                res[idx] += (idx - open + 1);
                if(open > 0){
                    res[idx] += res[open - 1];
                }
                maxi = max(maxi,res[idx]);
            }
        }
        return maxi;
    }
};