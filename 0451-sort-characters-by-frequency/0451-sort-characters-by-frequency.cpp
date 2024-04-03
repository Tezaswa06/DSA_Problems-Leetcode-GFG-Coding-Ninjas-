class Solution {
public:
    string frequencySort(string s) {
        vector<int>freqarr(256);

        for(char val : s){
            freqarr[val]++;
        }

        vector<vector<char>>buckets(s.size()+1);

        for(int i = 0 ; i < 256 ; i++){
            int count = freqarr[i];
            if(count == 0){
                continue;
            }
            buckets[count].push_back(static_cast<char>(i));
        }

        int index = 0;
        for(int bucket = 1 ; bucket < buckets.size() ; bucket++){
            for(char val : buckets[bucket]){
                for(int freq = 0; freq < bucket ; freq++){
                    s[index] = val;
                    index++;
                }
            }
        }
        reverse(s.begin(),s.end());
        return s;
    }
};