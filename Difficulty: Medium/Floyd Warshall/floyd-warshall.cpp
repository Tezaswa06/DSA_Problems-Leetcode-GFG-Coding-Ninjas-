//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>& dist){
	    int n = dist.size();
	    
	    for(int inter=0; inter<n; inter++){
	        for(int src=0; src<n; src++){
	            for(int dest=0; dest<n; dest++){
	                if(src == dest){
	                    continue;
	                }
	                if(dist[src][inter] == -1){
	                    continue;
	                }
	                if(dist[inter][dest] == -1){
	                    continue;
	                }
	                if(dist[src][dest] == -1){
	                    dist[src][dest] = dist[src][inter] + dist[inter][dest];
	                }
	                else{
	                    dist[src][dest] = min(dist[src][inter] + dist[inter][dest] , dist[src][dest]);
	                }
	            }
	        }
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends