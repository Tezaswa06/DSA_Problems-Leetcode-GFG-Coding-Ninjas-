class Solution {
public:
    bool ispalindrome(string s,int left,int right){
        
        while(left<=right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        
        while(start<=end){
            if(s[start]==s[end]){
                start++;
                end--;
            }
            else{
                return ispalindrome(s,start+1,end) || ispalindrome(s,start,end-1);
            }
        }
        return true;
    }
};