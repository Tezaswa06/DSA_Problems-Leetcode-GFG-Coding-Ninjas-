//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	
	int index;
	vector<int>topo;
	
	void toposort(int src,vector<bool>& vis, vector<vector<int>>& adj){
	    if(vis[src] == true){
	        return;
	    }
	    vis[src] = true;
	    for(int nbr : adj[src]){
	        toposort(nbr,vis,adj);
	    }
	    topo[index--] = src;
	}
	
	void dfs(int src,vector<bool>& vis,vector<vector<int>>& revGraph){
	    if(vis[src] == true){
	        return;
	    }
	    vis[src] = true;
	    for(int nbr : revGraph[src]){
	        dfs(nbr,vis,revGraph);
	    }

	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        index = V-1;
        topo.resize(V);
        
        vector<bool>vis(V,false);
        for(int idx=0; idx<V; idx++){
            toposort(idx,vis,adj);
        }
        
        vector<vector<int>> revGraph(V);
        for (int src = 0; src < V; src++) {
            for (int nbr : adj[src]) {
                revGraph[nbr].push_back(src);
            }
        }
        
        int scc = 0;
        fill(vis.begin(), vis.end(), false);
        for(int i=0; i<V; i++){
            int src = topo[i];
            if(vis[src] == false){
                dfs(src, vis, revGraph);
                scc++;
            }
        }
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends