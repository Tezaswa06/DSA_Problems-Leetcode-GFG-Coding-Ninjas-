//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    char get(int n){
        if(n < 10){
            return '0' + n;
        }
        if(n == 10){
            return 'A';
        }
        if(n == 11){
            return 'B';
        }
        if(n == 12){
            return 'C';
        }
        if(n == 13){
            return 'D';
        }
        if(n == 14){
            return 'E';
        }
        return 'F';
    }
    string getNumber(int B, int N)// required base -> B and given number -> N
    {
        string res;
        while(N > 0){
            char remainders = get(N % B);
            res.push_back(remainders);
            N = N / B;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int B,N;
        cin>>B>>N;
        Solution ob;
        string ans  = ob.getNumber(B,N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends