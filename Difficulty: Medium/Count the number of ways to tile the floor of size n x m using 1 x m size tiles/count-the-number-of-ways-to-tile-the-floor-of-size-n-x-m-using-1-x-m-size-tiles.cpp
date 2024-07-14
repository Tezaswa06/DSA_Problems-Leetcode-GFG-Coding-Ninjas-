//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// memoization

// class Solution{
// 	public:
	
// 	int mod = 1000000007;
// 	int memo(int n,int m,vector<int>& dp){
// 	    if(n < m){
// 	        return 1;
// 	    }
// 	    if(n == m){
// 	        return 2;
// 	    }
// 	    if(dp[n] != -1){
// 	        return dp[n];
// 	    }
// 	    int ans1 = memo(n-1,m,dp);
// 	    int ans2 = memo(n-m,m,dp);
	    
// 	    return dp[n] = (ans1 + ans2) % mod;
// 	}
// 	int countWays(int n, int m)
// 	{
// 	     vector<int>dp(n + 1,-1);
// 	     return memo(n,m,dp);
// 	}
// };

// space optimization
class Solution{
	public:
	    int mod = 1000000007;
	    
		int countWays(int n, int m)
	{
	    if(n < m){
	        return 1;
	    }
	    if(n == m){
	        return 2;
	    }
	    deque<int>dp;
	    for(int i=1; i<m; i++){
	        dp.push_back(1);// inserting the base case in the dp n < m
	    }
	    dp.push_back(2); //  n == m
	    
	    for(int i=m+1; i<=n; i++){
	        int ans = (dp.front() + dp.back()) % mod; 
	        dp.pop_front();
	        dp.push_back(ans);
	    }
	    return dp.back();
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.countWays(n, m);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends