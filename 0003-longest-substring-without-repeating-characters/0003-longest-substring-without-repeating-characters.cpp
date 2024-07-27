class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>freq;
        int left = 0;
        int maxlength = 0;

        for(int right=0; right<s.size(); right++){
            char ch = s[right];
            freq[ch]++;

            while(freq[ch] > 1){
                char leftChar = s[left];
                freq[leftChar]--;
                left++;
            }
            maxlength = max(maxlength,right-left+1);
        }
        return maxlength;
    }
};