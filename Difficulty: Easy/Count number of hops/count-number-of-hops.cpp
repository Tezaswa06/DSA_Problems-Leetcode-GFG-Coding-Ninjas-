//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    
    const long long MOD = 1e9 + 7;
    
    long long memoization(long long n,vector<long long>& dp){
        if(n == 0){
            return 1;
        }
        if(n < 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        long long ans1 = memoization(n-1,dp) % MOD;
        long long ans2 = memoization(n-2,dp) % MOD;
        long long ans3 = memoization(n-3,dp) % MOD;
        
        dp[n] = (ans1 + ans2 + ans3)% MOD;
        return dp[n];
    }
    long long tabulation(long long n,vector<long long>& dp){
        dp[0] = 1;
        for(long long i=1; i<=n; i++){
            long long ans1 = (i - 1) >= 0 ? dp[i-1] : 0;
            long long ans2 = (i-2) >= 0 ? dp[i-2] : 0;
            long long ans3 = (i-3) >= 0 ? dp[i-3] : 0;
            dp[i] = (ans1 + ans2 + ans3)% MOD;
        }
        return dp[n];
    }
    long long countWays(long long n)
    {
        vector<long long>dp(n+1,-1);
        return memoization(n,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends