class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<bool>unbalanced(s.size());

        stack<int>stk;

        for(int idx = 0 ; idx < s.size() ; idx++){
            if(s[idx] == '('){
                stk.push(idx);
                unbalanced[idx] = true;
            }
            else if(s[idx] == ')'){
                if(stk.size() > 0){
                    unbalanced[stk.top()] = false;
                    stk.pop();
                }
                else{
                    unbalanced[idx] = true;
                }
            }
        }
        string res;
        for(int idx = 0 ; idx < s.size() ; idx++){
            if(unbalanced[idx] == false){
                res.push_back(s[idx]);
            }
        }
        return res;
    }
};