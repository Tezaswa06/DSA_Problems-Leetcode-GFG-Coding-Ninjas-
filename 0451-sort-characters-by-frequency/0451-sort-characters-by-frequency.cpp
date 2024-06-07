class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // Calculate the frequency of each character
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            freq[ch]++;
        }

        unordered_map<int, vector<char>> freq2;
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            char ch = it->first;
            int f = it->second;
            freq2[f].push_back(ch);
        }

        // Build the result string
        string res;
        for (int f = s.length(); f >= 1; f--) {
            if (freq2.find(f) != freq2.end()) {
                for (char ch : freq2[f]) {
                    res.append(f,ch);
                }
            }
        }

        return res;
    }
};