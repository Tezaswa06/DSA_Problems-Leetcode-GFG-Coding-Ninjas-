class Solution {
public:
    bool isvowel(char ch){
        ch = tolower(ch);
        if(ch =='a'||ch =='e'||ch =='i'||ch =='o'||ch =='u'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int start = 0;
        int end = s.size()-1;

        while(start<=end){
            if(isvowel(s[start])==true && isvowel(s[end])==true){
                swap(s[start],s[end]);
                start++;
                end--;
            }
            else if(isvowel(s[start])==false){
                start++;
            }
            else{
                end--;
            }
        }
        return s;
    }
};