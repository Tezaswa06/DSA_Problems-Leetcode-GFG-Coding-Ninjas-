class Solution {
public:
    int helper(string s,int k, char ch){
        int left = 0;
        int replacement = 0;
        int maxlen = 0;

        for(int right=0; right<s.size(); right++){
            if(s[right] != ch){
                replacement++;
            }
            while(replacement > k){
                if(s[left] != ch){
                    replacement--;
                }
                left++;
            }
            maxlen = max(maxlen,right-left+1);
        }
        return maxlen;
    }
    int characterReplacement(string s, int k) {
        int ans = 0;
        for(int i=0; i<26; i++){
            ans = max(ans,helper(s,k,i+'A'));
        }
        return ans;
    }
};