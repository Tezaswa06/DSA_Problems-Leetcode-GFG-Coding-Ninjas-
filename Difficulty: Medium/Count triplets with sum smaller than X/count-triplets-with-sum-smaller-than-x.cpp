//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

  public:
    long long twoSumSmaller(long long arr[],int n, long long right,long long target){
        long long count = 0;
        long long left = 0;
        
        while(left < right){
            int sum = arr[left] + arr[right];
            
            if(sum < target){
                count += right-left;
                left++;
            }
            else{
                right--;
            }
        }
        return count;
    }
    long long countTriplets(int n, long long sum, long long arr[]) {
        sort(arr,arr + n);
        long long ans = 0;
        
        for(long long first=n-1; first>=0; first--){
            ans += twoSumSmaller(arr,n,first-1,sum - arr[first]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long sum;
        cin >> n >> sum;
        long long arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countTriplets(n, sum, arr);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends