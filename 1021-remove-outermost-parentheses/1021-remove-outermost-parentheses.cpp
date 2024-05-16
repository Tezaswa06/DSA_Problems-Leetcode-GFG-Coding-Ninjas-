class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<bool>isOuter(s.size());

        stack<int>stk;
        // we are pushing those characters in the stack which are '(' and poping out the opening brackets when there is a parathesis match and if the matched paranthesis are outer brackets then we will left those brackets and return those brackets which are inside the outer brackets by taking a bool array
        for(int idx = 0 ; idx < s.size() ; idx++){ // here current index is closing character
            if(s[idx] == '('){
                stk.push(idx);
            }
            else{
                int open = stk.top(); // 
                stk.pop();
                if(stk.size() == 0){
                    isOuter[idx] = isOuter[open] = true;
                }
            }
        }
        string res;
        for(int i = 0 ; i < s.size() ; i++){
            if(isOuter[i] == false){
                res.push_back(s[i]);
            }
        }
        return res;
    }
};