//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct Pair{
    int node;
    int weight;
    
    Pair(int node,int weight){
        this -> node = node;
        this -> weight = weight;
    }
};
class Compare{
    public:
    bool operator()(auto a,auto b){
        return a.weight > b.weight;
    }
};
class Solution
{
	public:
	
    int spanningTree(int n, vector<vector<int>> g[])
    {
        vector<vector<Pair>> adj(n);
        for (int i = 0; i < n; i++) {
            for (auto pairs : g[i]) {
                adj[i].push_back(Pair(pairs[0], pairs[1]));
            }
        }
        
        priority_queue<Pair,vector<Pair>,Compare>q;
        q.push(Pair(0,0));
        
        vector<bool>vis(n);
        int cost = 0;
        
        while(q.size() > 0){
            Pair p = q.top();
            q.pop();
            
            if(vis[p.node] == true){
                continue;
            }
            vis[p.node] = true;
            cost = cost + p.weight;
            for(Pair nbr : adj[p.node]){
                q.push(Pair(nbr.node,nbr.weight));
            }
        }
        return cost;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends