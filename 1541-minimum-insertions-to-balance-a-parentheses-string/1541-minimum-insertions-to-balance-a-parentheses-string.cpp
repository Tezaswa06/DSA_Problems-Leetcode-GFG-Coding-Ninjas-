class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int addition = 0;

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];

            if(ch == '('){
                open++;
            }
            else if(ch == ')'){
                if(i + 1 < s.size() && s[i+1] == ')'){
                    i++;
                }
                else{
                    addition++;
                }

                if(open > 0){
                    open--;
                }
                else{
                    addition++;
                }
            }
        }
        addition += 2* open;
        return addition;
    }
};