//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// class Solution {
//   public:
//     int gameOfXor(int N , int A[]) {
//         int res = 0;
//         for(int i=0; i<N; i++){
//             int occurences = (i + 1) * (N - i);
//             if((occurences & 1) == 1){//if occurences are odd no of time then only we will be performing xor operation
//                 res = res ^ A[i];
//             }
//         }
//         return res;
//     }
// };


class Solution {
  public:
    int gameOfXor(int N , int A[]) {
        if(N % 2 == 0){
            return 0;
        }
        int res = 0;
        for(int i=0; i<N; i+=2){
            res = res ^ A[i];
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        for(int i=0 ; i<N ; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.gameOfXor(N,A) << endl;
    }
    return 0;
}
// } Driver Code Ends