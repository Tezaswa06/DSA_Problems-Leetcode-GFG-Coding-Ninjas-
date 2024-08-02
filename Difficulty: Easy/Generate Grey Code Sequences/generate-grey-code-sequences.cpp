//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*Returns an array of all n-bit gray codes sequence.
You are required to complete below method. */
class Solution{
  public:
    vector<string> generateCode(int n)
    {
        if(n == 1){
            return {"0","1"};
        }
        
        vector<string>res = generateCode(--n);
        for(int i=res.size()-1; i>=0; i--){
            res.push_back("1" + res[i]);
            res[i] = "0" + res[i];
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution obj;
		vector <string> res = obj.generateCode(n);
		for (string i : res) cout << i << " ";
        cout<<endl;
	}
	return 0;
}


// } Driver Code Ends