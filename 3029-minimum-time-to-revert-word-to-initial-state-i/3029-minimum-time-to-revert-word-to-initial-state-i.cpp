// approach 1
// class Solution {
// public:
//     int minimumTimeToInitialState(string word, int k) {
//        int i=0,j=k,count=1,n=word.size();
//        while(j<n){
           
//            if(word[i]==word[j]){
//                i++;
//                j++;
//            }
//            else{
//                i=0;
//                count++;
//                j=count*k;
//            }
//        } 
//        return count;
//     }
// };

// approach 2
class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int ans = 0;
        for(int i=1; i<=word.size(); i++){// in this loop i determines no of sec used
            int d = i * k;
            if(d >= word.size()){
                return i;
            }

            bool ok = true;
            for(int j=d; j<word.size(); j++){
                if(word[j] != word[j-d]){
                    ok = false;
                    break;
                }
            }
            if(ok == true){
                return i;
            }
        }
        return 0;
    }
};