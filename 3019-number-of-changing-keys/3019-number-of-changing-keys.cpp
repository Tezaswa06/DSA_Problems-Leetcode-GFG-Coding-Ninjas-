// My Approach

// class Solution {
// public:
//     int countKeyChanges(string s) {
//         string lower;
//         int count = 0;
//         for(char ch : s){
//             lower.push_back(tolower(ch));
//         }
//         cout<<lower;
//         for(int i=0; i<lower.size(); i++){
//             char ch1 = lower[i];
//             char ch2 = lower[i+1];
//             if(i+1 < s.size()){
//                 if(ch1 != ch2){
//                     count++;
//                 }
//                 else{
//                     continue;
//                 }
//             }
//         }
//         return count;
//     }
// };

// approach 2
class Solution {
public:
    int countKeyChanges(string s) {
        int count = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] += 32;
            }
            if(i > 0 && s[i] != s[i-1]){
                count++;
            }
        }
        return count;
    }
};