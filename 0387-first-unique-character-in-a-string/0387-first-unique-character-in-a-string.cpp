class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>freqarr(26);
        
            for(char ch : s){
                freqarr[ch-'a']++;
            }
            for(int i=0;i<s.size();i++){
                char ch = s[i];
                if(freqarr[ch - 'a'] == 1){
                    return i;
                }
            }
        return -1;
    }
};