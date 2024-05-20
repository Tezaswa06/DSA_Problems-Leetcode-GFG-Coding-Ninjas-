class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string res;
        for(char ch: num){
            while(k > 0 && res.size() > 0 && res[res.size() - 1] > ch){
                res.pop_back();
                k--;
            }
            res.push_back(ch);
        }

        while(k > 0){
            res.pop_back();
            k--;
        }
        int idx = 0;
        while(idx < res.size() && res[idx] == '0'){
            idx++;
        }
        if(idx == res.size()){
            return "0";
        }
        return res.substr(idx);
    }
};