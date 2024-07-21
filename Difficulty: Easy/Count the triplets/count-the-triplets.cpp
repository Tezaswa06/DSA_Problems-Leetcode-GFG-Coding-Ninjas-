//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int twoPointer(int arr[],int right,int target){
	    int left = 0;
	    int count = 0;
	    
	    while(left < right){
	        int sum = arr[left] + arr[right];
	        if(sum == target){
	            count++;
	            left++;
	            right--;
	        }
	        else if(sum > target){
	            right--;
	        }
	        else{
	            left++;
	        }
	    }
	    return count;
	}
	int countTriplet(int arr[], int n)
	{   
	    sort(arr, arr + n);
	    int ans = 0;
	    for(int last=n-1; last>=0; last--){
	        ans += twoPointer(arr,last-1,arr[last]);
	    }
	    return ans;
	    
	}
};

//{ Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}
// } Driver Code Ends