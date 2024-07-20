//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    vector<int> sumClosest(vector<int>& arr, int target)
    {
        int left = 0;
        int right = arr.size() - 1;
        
        sort(arr.begin(), arr.end());
        int absDiff = INT_MAX;
        int closestLeft = 0, closestRight = 0;
        
        while (left < right) {
            int sum = arr[left] + arr[right];
            
            if (sum == target) {
                return {arr[left], arr[right]};
            }
            
            if (abs(sum - target) < absDiff) {
                absDiff = abs(sum - target);
                closestLeft = left;
                closestRight = right;
            }
            
            if (sum > target) {
                right--;
            } else {
                left++;
            }
        }
        
        return {arr[closestLeft], arr[closestRight]};
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumClosest(arr, x);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends