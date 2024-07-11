//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	int memoization(int N,vector<int>& dp){
	    if(N == 1){
	        return 0;
	    }
	    if(dp[N] != -1){
	        return dp[N];
	    }
	    
	    int ans1 = (N % 2 == 0) ? memoization(N/2 , dp) : INT_MAX;
	    int ans2 = (N % 3 == 0) ? memoization(N/3 , dp) : INT_MAX;
	    int ans3 = memoization(N - 1 , dp);
	    
	    dp[N] = min(ans1,min(ans2,ans3)) + 1;
	    return dp[N];
	}
	int minSteps(int N) 
	{ 
	   vector<int>dp(N + 1, -1);
	   return memoization(N,dp);
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.minSteps(n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends