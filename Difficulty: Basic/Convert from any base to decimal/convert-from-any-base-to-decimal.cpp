//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int get(char val){
        if(val >= '0' && val <= '9'){
            return val - '0';
        }
        if(val == 'A'){
            return 10;
        }
        if(val == 'B'){
            return 11;
        }
        if(val == 'C'){
            return 12;
        }
        if(val == 'D'){
            return 13;
        }
        if(val == 'E'){
            return 14;
        }
        return 15;
    }
    int decimalEquivalent(string N, int b){
        int res = 0;
        int power = 1;
        
        for(int i=N.size()-1; i>=0; i--){
            char ch = N[i];
            int val = get(ch);
            if(val >= b){
                return -1;
            }
            res = res + power * val;
            power = power * b;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int b;
        cin>>b;
        string N;
        cin>>N;
        
        Solution ob;
        cout<<ob.decimalEquivalent(N, b)<<"\n";
    }
    return 0;
}
// } Driver Code Ends