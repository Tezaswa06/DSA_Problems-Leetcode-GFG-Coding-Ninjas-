class Solution {
public:
    int compress(vector<char>& chars) {
        int left = 0;
        int right = 0;
        vector<char>answer; 
        while(left<chars.size()){
            char ch = chars[left];
            int frequency = 0;
            while(right<chars.size() && chars[right]==ch){
                right++;
                frequency++;
            }
            answer.push_back(ch);
            if(frequency>1){
                string freqstr = to_string(frequency);
                for(char str: freqstr){
                    answer.push_back(str);
                }
            }
            left = right;
        }
        for(int i=0;i<answer.size();i++){
            chars[i] = answer[i];
        }
        return answer.size();

    }
};