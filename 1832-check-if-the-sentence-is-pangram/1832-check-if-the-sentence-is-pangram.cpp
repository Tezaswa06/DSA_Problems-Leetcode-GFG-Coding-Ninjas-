class Solution {
public:
    vector<int> frequencycount(string& sentence){
        vector<int> countchar(26,0);
        
        for(char ch : sentence){
            countchar[ch - 'a']++;
        }
        return countchar;
    }
    bool checkIfPangram(string sentence) {
        
        vector<int>freqcount = frequencycount(sentence);
        
        for(int i=0;i<26;i++){
            if(freqcount[i]<1){
                return false;
            }
        }
        return true;
    }
};