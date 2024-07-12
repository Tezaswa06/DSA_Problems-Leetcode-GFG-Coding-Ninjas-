//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends

class Solution{
public:
	long mod = 1000000007;
	
	long long memo(int noOfDigits,int prevDigit,vector<vector<long>>& dp){
	    if(noOfDigits == 0){
	        return 1;// empty string
	    }
	    if(dp[noOfDigits][prevDigit] != -1){
	        return dp[noOfDigits][prevDigit];
	    }
	    
	    long long append0 = memo(noOfDigits - 1,0,dp);
	    long long append1 = (prevDigit == 0) ? memo(noOfDigits - 1,1,dp) : 0;// prev 1 hoga to hum sirf 0 ki string ko call karenge
	    
	    return dp[noOfDigits][prevDigit] = (append0 + append1) % mod;
	}   
	
	long long countStrings(int n) {
	     vector<vector<long>>dp(n+1,vector<long>(2,-1));
	     return memo(n,0,dp);
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
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends