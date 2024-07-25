//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution{   
public:
    long maximumSumSubarray(int wind, vector<int> &arr , int N){
        long currSum = 0;
        for(long i=0; i<wind; i++){
            currSum += arr[i];
        }
        long maxSum = currSum;
        for(long i=wind; i<N; i++){
            long include = arr[i];// including the current element after window size
            long exclude = arr[i-wind];// excluding the first element to maintain the window size
            currSum += include - exclude;
            
            maxSum = max(currSum,maxSum);
        }
        return maxSum;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends