//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// DFS

// class Solution
// {
// 	public:
// 	vector<int>topo;
// 	int index;
// 	void dfs(int src, vector<int>adj[],vector<bool>&vis){
// 	    if(vis[src] == true){
// 	        return;
// 	    }
// 	    vis[src] = true;
// 	    for(int nbr : adj[src]){
// 	        dfs(nbr,adj,vis);
// 	    }
// 	    topo[index--] = src;
	    
// 	}
// 	vector<int> topoSort(int V, vector<int> adj[]) 
// 	{
// 	    vector<bool>vis(V,false);
// 	    index = V - 1;
// 	    topo.resize(V);
	    
// 	    for(int i=0; i<V; i++){
// 	        dfs(i,adj,vis);
// 	    }
	    
	    
// 	    return topo;
// 	}
// };

// BFS using Kahn's Algo

class Solution
{
	public:
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> incoming(V, 0);
        
        // Calculate the incoming degree for each node
        for (int i = 0; i < V; i++) {
            for (int node : adj[i]) {
                incoming[node]++;
            }
        }
	    // multisource bfs
	    vector<int>topo(V);
	    int push = 0;
	    int pop = 0;
	    for(int i=0; i<V; i++){
	        if(incoming[i] == 0){
	            topo[push++] = i;
	        }
	    }
	    
	    while(push < V){
	        int src = topo[pop++];
	        for(int nbr : adj[src]){
	            incoming[nbr]--;
	            if(incoming[nbr] == 0){
	                topo[push++] = nbr;
	            }
	        }
	    }
	    return topo;
	 }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
