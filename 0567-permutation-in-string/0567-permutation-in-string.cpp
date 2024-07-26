class Solution {
public:
    bool isEqual(vector<int>& reqFreq, vector<int>& currFreq){
        for(int i=0; i<26; i++){
            if(reqFreq[i] != currFreq[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int>reqFreq(26);
        vector<int>currFreq(26);
        int window = s1.size();

        for(int i=0; i<window; i++){
            reqFreq[s1[i] - 'a']++;
        }
        for(int i=0; i<s2.size(); i++){
            currFreq[s2[i] - 'a']++;
            if(i >= window){
                currFreq[s2[i-window] - 'a']--;
            }
            if(isEqual(reqFreq,currFreq) == true){
                return true;
            } 
        }
        return false;
    }
};