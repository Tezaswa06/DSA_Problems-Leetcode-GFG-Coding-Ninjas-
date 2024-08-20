class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp;
        for(char val : magazine){
            mp[val]++;
        }
        for(char val : ransomNote){
            if(mp[val] > 0){
                mp[val]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};