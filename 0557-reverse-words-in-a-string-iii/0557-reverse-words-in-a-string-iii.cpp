class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        int right = 0;
        
        
        while(right<s.size()){
            while(right<s.size() && s[right]!=' '){
                right++;
            }
            int start = left;
            int end = right-1;
            while(start<=end){
                    swap(s[start],s[end]);
                    start++;
                    end--;
                }
            left = right +1;
            right = right+1;
        }
        return s;
            
    }
};