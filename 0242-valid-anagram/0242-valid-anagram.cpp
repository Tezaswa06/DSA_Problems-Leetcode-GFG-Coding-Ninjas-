class Solution {
public:
    vector<int> getfrequencycount(string &s){
        vector<int>freq(26,0);

        for(char ch: s){
            freq[ch-'a']++; // here we have subtracted the character -'a' because if we do frequency[ch]++ then and our character is a suppose and we know the ascii value of a that is 97 and we know that our array size is 26 only that's why we have subteacted each and every character with a to get the index
        }
        return freq;
    }
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        vector<int>frequencycount1 = getfrequencycount(s);
        vector<int>frequencycount2 = getfrequencycount(t);

        for(int i=0;i<26;i++){
            if(frequencycount1[i]!=frequencycount2[i]){
                return false;
            }
        }
        return true;
    }
};