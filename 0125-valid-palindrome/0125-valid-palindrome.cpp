class Solution {
public:
    bool isalphanumeric(char ch){
        if(ch>='a' && ch<='z'){
            return true;
        }
        if(ch>='A' && ch<='Z'){
            return true;
        }
        if(ch>='0' && ch<='9'){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        
        for(char &character : s){
            character = tolower(character);
            cout<<character;
            
        }
        int left = 0;
        int right = s.size()-1;
        while(left<=right){
            if(isalphanumeric(s[left])==false){
                left++;
                continue;
            }
            if(isalphanumeric(s[right])==false){
                right--;
                continue;
            }
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};