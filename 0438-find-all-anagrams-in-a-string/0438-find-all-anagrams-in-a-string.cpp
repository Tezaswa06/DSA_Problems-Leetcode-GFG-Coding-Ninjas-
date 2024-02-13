class Solution {
public:
    vector<int> frequencycount(string s){
        vector<int>freqarr(26,0);
        for(char ch : s){
            freqarr[ch - 'a']++;
        }
        return freqarr;
    }
    bool isanagram(string &s,string &p){
        if(s.size()!=p.size()){
            return false;
        }
        
        vector<int>freqcountstring1 = frequencycount(s);
        vector<int>freqcountstring2 = frequencycount(p);
        for(int i=0;i<26;i++){
            if(freqcountstring1[i]!=freqcountstring2[i]){
                return false;
            }
        }

        return true;

    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>answer;
        int p2 = 0;
        if(p.size()>s.size()){
            return answer;
        }
        for(int i=0;i<=s.size()-p.size();i++){
            string str;
            while(p2<p.size()){
                str.push_back(s[p2+i]);
                p2++;
            }
            

            p2 = 0;
         
            
            if(isanagram(str,p)==true){
                answer.push_back(i);
            }
        } 
        return answer;
    }
};