//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int src, vector<int> adj[] , vector<int>& vis){
        if(vis[src] == 1){
            return true;
        }
        if(vis[src] == 2){
            return false;
        }
        
        vis[src] = 1;//visiting the node for the fist time in preorder
        for(int nbr : adj[src]){
            if(dfs(nbr,adj,vis) == true){
                return true;
            }
        }
        vis[src] = 2; //  visiting node in postorder
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>vis(V);// 0 -> unvisited, 1 -> preorder , 2 -> postorder
        
        for(int i=0; i<V; i++){
            if(vis[i] > 0){//already visited component then simply return
                continue;
            }
            if(dfs(i,adj,vis) == true){
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends