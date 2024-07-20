//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int target)
	{
	    vector<int>arr1;
	    vector<int>arr2;
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            arr1.push_back(mat1[i][j]);
	        }
	    }
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            arr2.push_back(mat2[i][j]);
	        }
	    }
	    
	    int p = arr1.size()-1;
	    int q = arr2.size()-1;
	    int left = 0;
	    int right = q;
	    int count = 0;
	    
	    while(left <= p && right >= 0){
            int sum = arr1[left] + arr2[right];
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
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}
// } Driver Code Ends