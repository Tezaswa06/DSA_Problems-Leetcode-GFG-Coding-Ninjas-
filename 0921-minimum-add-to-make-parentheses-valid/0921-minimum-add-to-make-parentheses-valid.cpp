class Solution {
public:
    int minAddToMakeValid(string s) {
        int unbalanced_open_brackets = 0;
        int unbalanced_close_brackets = 0;

        for(char ch : s){
            if(ch == '('){
                unbalanced_open_brackets++;
            }
            else{
                if(unbalanced_open_brackets > 0){
                    unbalanced_open_brackets--;
                }
                else{
                    unbalanced_close_brackets++;
                }
            }
        }
        return unbalanced_open_brackets + unbalanced_close_brackets;
    }
};