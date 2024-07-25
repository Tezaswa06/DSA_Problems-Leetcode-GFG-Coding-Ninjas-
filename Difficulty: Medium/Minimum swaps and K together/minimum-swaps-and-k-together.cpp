//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int window = 0;
        for(int i=0; i<n; i++){
            if(arr[i] <= k){
                window++;
            }
        }
        
        int moreThanK = 0;
        for(int i=0; i<window; i++){// current window me jitne bhi nunbers k se bade hoyenge  ko hume minimise karna hai 
            if(arr[i] > k){         // unka count rakhenge kyuki utne hi swaps hoyenge aur unhi
                moreThanK++;
            }
        }
        
        int minSwaps = moreThanK;
        for(int i=window; i<n; i++){
            if(arr[i] > k){ // include
                moreThanK++;
            }
            if(arr[i - window] > k){// exclude agar greater than k hai to moreThanK ko decrement karenge
                moreThanK--;
            }
            minSwaps = min(minSwaps,moreThanK);
        }
        return minSwaps;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends