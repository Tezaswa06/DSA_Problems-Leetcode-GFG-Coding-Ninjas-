class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        
        sort(dictionary.begin(),dictionary.end());
        string answer;
        string maxstr = "";
        
        for(auto str : dictionary){
            int p1 = 0;
            int p2 = 0;
            
            while(p1<str.size() && p2<s.size()){
                if(str[p1]==s[p2]){
                    p1++;
                    p2++;
                }
                else{
                    p2++;
                }
                if(p1==str.size()){
                    answer = str;
                }
                if(answer.size()>maxstr.size()){
                    maxstr = answer;
                }
            }
            answer.clear();
        }
        return maxstr;
    }
};