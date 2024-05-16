class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;

        for(int i = 0 ; i < s.size() ; i++){
            char ch = s[i];

            if(ch == '(' || ch == '[' || ch == '{'){
                stk.push(ch);
            }
            else{
                if(stk.size() == 0)  return false; // extra closing character
                if(ch == ')' && stk.top() == '('){
                    stk.pop();
                }
                else if(ch == ']' && stk.top() =='['){
                    stk.pop();
                }
                else if(ch == '}' && stk.top() =='{'){
                    stk.pop();
                }
                else{
                    return false;
                }
            }
        }
        return (stk.size() == 0); //checking if there exists extra opening character
    }
};