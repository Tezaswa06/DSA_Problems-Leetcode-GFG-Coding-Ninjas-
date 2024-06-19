//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    vector<int>topo;
    int index;
    void dfs(int src,vector<int>adj[],vector<bool>& vis){
        if(vis[src] == true){
            return;
        }
        vis[src] = true;
        for(int nbr : adj[src]){
            dfs(nbr,adj,vis);
        }
        topo[index--] = src;
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<bool>vis(V,false);
	    topo.resize(V);
	    index = V - 1;
	    
	    for(int i=0; i<V; i++){
	        dfs(i,adj,vis);// first time we found dfs to find the topo sort
	    }
	    
	    vis.assign(V,false);
	    index = V - 1;
	    dfs(topo[0],adj,vis);// second time we called dfs to confirm the ans
	    
	    for(int i=0; i<V; i++){
	        if(vis[i] == false){
	            return -1;
	        }
	    }
	    return topo[0];
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
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends