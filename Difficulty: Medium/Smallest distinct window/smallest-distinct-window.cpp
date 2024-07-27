//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        unordered_set<char>uniqueChar(str.begin(),str.end());
        int requiredChar = uniqueChar.size();
        int left = 0;
        int matchCount = 0;
        int minLen = INT_MAX;
        unordered_map<char,int>window;
        
        for(int right=0; right<str.size(); right++){
            char ch = str[right];
            window[ch]++;
            
            if(window[ch] == 1){
                matchCount++;
            }
            while(matchCount == requiredChar){
                if(right-left+1 < minLen){
                    minLen = right-left+1;
                }
                char leftChar = str[left];
                window[leftChar]--;
                if(window[leftChar] == 0){
                    matchCount--;
                }
                left++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends