//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int toggleBits(int N , int l , int r) {
        for(int i=l-1; i<=r-1; i++){
            int mask = (1 << i);
            N = (N ^ mask);
        }
        return N;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,l,r;
        
        cin>>n>>l>>r;

        Solution ob;
        cout << ob.toggleBits(n,l,r) << endl;
    }
    return 0;
}
// } Driver Code Ends