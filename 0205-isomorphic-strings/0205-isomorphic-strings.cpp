class Solution {
public:
    bool createmapping(string& s, string& t){
        vector<char>map(256,'0');

        for(int i=0;i<s.size();i++){
            char ch1 = s[i];
            char ch2 = t[i];

            if(map[ch1]!='0' && map[ch1]!=ch2){
                return false;
            }
            map[ch1] = ch2;
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        return createmapping(s,t) && createmapping(t,s);
    }
};