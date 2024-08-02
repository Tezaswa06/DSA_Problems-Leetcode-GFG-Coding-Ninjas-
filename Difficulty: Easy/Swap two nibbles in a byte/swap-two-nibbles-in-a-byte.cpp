//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int swap(int n, int left, int right){
        int leftMask = (1 << left);
        int rightMask = (1 << right);
        
        bool isLeftSet = ((n & leftMask) != 0);
        bool isRightSet = ((n & rightMask)!= 0);
        
        if(isLeftSet != isRightSet){
            n = n ^ leftMask;
            n = n ^ rightMask;
        }
        return n;
    }
    int swapNibbles(int n) {
        n = swap(n,0,4);
        n = swap(n,1,5);
        n = swap(n,2,6);
        n = swap(n,3,7);
        return n;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends