//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	int findMaxSubarraySum(long long arr[], int n, long long x)
	{
        long long left = 0;
        long long sum = 0;
        long long maxsum = 0;
        
        for(int right=0; right<n; right++){
            sum += arr[right];
            
            while(sum > x ){
                sum -= arr[left];
                left++;
            }
            maxsum = max(maxsum,sum);
        }
        return maxsum;
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
        cin>>n;
        
        long long a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        
        long long sum;
        cin >> sum;
        

        Solution ob;
		cout << ob.findMaxSubarraySum(a, n, sum);
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends