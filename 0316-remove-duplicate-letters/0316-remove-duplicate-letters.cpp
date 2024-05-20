class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>freq(26);// no of characters are 26
        vector<bool>visited(26);

        for(char ch : s){
            freq[ch -'a']++;
        }

        string res;

        for(char ch : s){
            freq[ch - 'a']--;
            if(visited[ch - 'a'] == true){
                continue;
            }
            visited[ch - 'a'] = true;

            while(res.size() > 0){
                char top = res[res.size() - 1];
                if(top > ch && freq[top - 'a'] > 0){
                    res.pop_back();
                    visited[top - 'a'] = false;
                }
                else{
                    break;
                }
            }
            res.push_back(ch);
        }
        return res;
    }
};