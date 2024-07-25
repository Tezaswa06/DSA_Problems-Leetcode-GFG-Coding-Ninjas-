//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
    
    vector<long long>res(N-K+1);
    deque<long long>q;
    for(long long i=0; i<K; i++){
        if(A[i] < 0){
            q.push_back(A[i]);
        }
    }
    long long window = 0;
    res[window++] = (q.size() == 0) ? 0 : q.front();
    for(long long i=K; i<N; i++){
        if(q.size() > 0 && A[i-K] < 0){// agar q.front ka current index se bahar jaa rha hoga to pop kar denge
            q.pop_front();
        }
        if(A[i] < 0){// if negative
            q.push_back(A[i]);
        }
        res[window++] = (q.size() == 0) ? 0 : q.front();
    }
    return res;
 }