//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution {
  public:
    vector<int>disc;
    vector<int>low;
    int timep = 0;
    set<int>articulationPointsSet;
    
    void dfs(int  src, int parent,vector<int>adj[]){
        disc[src] = low[src] = timep;
        timep++;
        
        int dfsCount = 0;
        
        for(auto nbr : adj[src]){
            if(nbr == parent){
                continue;
            }
            if(disc[nbr] >= 0){
                low[src] = min(low[src],disc[nbr]);
            }
            else{
                dfs(nbr,src,adj);
                dfsCount++;
                
                if(parent != -1 && low[nbr] >= disc[src]){
                    articulationPointsSet.insert(src);
                }
                low[src] = min(low[src],low[nbr]);
            }
        }
        if(parent == -1 && dfsCount > 1){
            articulationPointsSet.insert(src);
        }
    }
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        disc.resize(n,-1);
        low.resize(n);
        dfs(0,-1,adj);
        
        vector<int>res;
        for(auto ap : articulationPointsSet){
            res.push_back(ap);
        }
        if(res.size() == 0){
            return {-1};
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends