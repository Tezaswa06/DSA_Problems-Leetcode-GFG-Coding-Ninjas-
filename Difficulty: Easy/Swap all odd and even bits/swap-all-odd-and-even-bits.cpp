//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    unsigned int swap(unsigned int n,int left,int right){
        int leftMask = (1 << left);
        int rightMask = (1 << right);
        
        bool isLeftSet = ((n & leftMask) != 0);
        bool isRightSet = ((n & rightMask) != 0);
        
        if(isLeftSet != isRightSet){
            n = n ^ leftMask;
            n = n ^ rightMask;
        }
        return n;
    }
    unsigned int swapBits(unsigned int n)
    {
    	for(int bit=0; bit<32; bit=bit+2){
    	    n = swap(n,bit,bit+1);
    	}
    	return n;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;//testcases
	while(t--)
	{
		unsigned int n;
		cin>>n;//input n
		
		Solution ob;
		//calling swapBits() method
		cout << ob.swapBits(n) << endl;
	}
	return 0;
}
// } Driver Code Ends