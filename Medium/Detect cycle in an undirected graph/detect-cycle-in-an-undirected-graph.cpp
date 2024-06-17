//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// dfs
class Solution {
  public:
    bool DFS(int src, int parent, vector<int> adj[], vector<bool>&vis){
        if(vis[src] == true){ //if we visited alredy visited node the cycle found
            return true;
        }
        vis[src] = true;
        for(int nbr : adj[src]){
            if(nbr == parent){ // matlab agar current node parent ke braabar hai to lot jaao
                continue;
            }
            if(DFS(nbr,src,adj,vis)==true){// here src is denoting as parent
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>vis(V,false);
        
        for(int i=0; i<V; i++){// this for loop we have created to handle multiple components
            if(vis[i] == false && DFS(i,-1,adj,vis) == true){
                return true;
            }
        }
        return false;
    }
};
// bfs
class Solution {
  public:
    struct Pair{
        int src;
        int parent;
        
        Pair(int src,int parent){
            this -> src = src;
            this -> parent = parent;
        }
    };
    bool BFS(int src,vector<int> adj[],vector<bool>& vis){
        queue<Pair>q;
        q.push(Pair(src, -1));
        
        while(q.size() > 0){
            Pair p = q.front();
            q.pop();
            
            if(vis[p.src] == true){
                return true;
            }
            vis[p.src] = true;
            
            for(int nbr : adj[p.src]){
                if(nbr == p.parent){
                    continue;
                }
                q.push(Pair(nbr,p.src));
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>vis(V,false);
        
        for(int i=0; i<V; i++){
            if(vis[i] == false && BFS(i,adj,vis) == true){
                return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
