//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

    int mod = 1000000007;
    
    long countFreindsPairings(int n,vector<long>& dp){
        if(n == 0 || n == 1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        
        long single = countFreindsPairings(n-1,dp);
        long pair = ((n-1) * countFreindsPairings(n-2,dp)) % mod;
        
        return dp[n] = (single + pair) % mod;
    }
    int countFriendsPairings(int n) 
    { 
        vector<long>dp(n+1,-1);
        return countFreindsPairings(n,dp);
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends