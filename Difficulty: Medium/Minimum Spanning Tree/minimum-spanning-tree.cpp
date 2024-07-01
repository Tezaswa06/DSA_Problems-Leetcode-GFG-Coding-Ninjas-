//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// prims

//struct Pair{
//     int node;
//     int weight;
    
//     Pair(int node,int weight){
//         this -> node = node;
//         this -> weight = weight;
//     }
// };
// class Compare{
//     public:
//     bool operator()(auto a,auto b){
//         return a.weight > b.weight;
//     }
// };
// class Solution
// {
// 	public:
	
//     int spanningTree(int n, vector<vector<int>> g[])
//     {
//         vector<vector<Pair>> adj(n);
//         for (int i = 0; i < n; i++) {
//             for (auto pairs : g[i]) {
//                 adj[i].push_back(Pair(pairs[0], pairs[1]));
//             }
//         }
        
//         priority_queue<Pair,vector<Pair>,Compare>q;
//         q.push(Pair(0,0));
        
//         vector<bool>vis(n);
//         int cost = 0;
        
//         while(q.size() > 0){
//             Pair p = q.top();
//             q.pop();
            
//             if(vis[p.node] == true){
//                 continue;
//             }
//             vis[p.node] = true;
//             cost = cost + p.weight;
//             for(Pair nbr : adj[p.node]){
//                 q.push(Pair(nbr.node,nbr.weight));
//             }
//         }
//         return cost;
//     }
// };

// kruskal
class Pair {
public:
    int src;
    int nbr;
    int wt;

    Pair(int src, int nbr, int wt) {
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};

class compare {
public:
    bool operator()(const Pair& a, const Pair& b) {
        return a.wt < b.wt;
    }
};

class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n, -1);
        rank.resize(n, 1);
    }

    void union_set(int a, int b) {
        int pa = findPar(a);
        int pb = findPar(b);

        if (pa == pb) {
            return;
        }
        if (rank[pa] > rank[pb]) {
            parent[pb] = pa;
            rank[pa] += rank[pb];
        } else {
            parent[pa] = pb;
            rank[pb] += rank[pa];
        }
    }

    int findPar(int a) {
        if (parent[a] == -1) {
            return a;
        }
        return parent[a] = findPar(parent[a]);
    }
};

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<Pair> edges;
        for (int src = 0; src < V; src++) {
            for (auto& edge : adj[src]) {
                int nbr = edge[0];
                int wt = edge[1];

                if (src > nbr) {
                    edges.emplace_back(src, nbr, wt);
                }
            }
        }

        DSU sets(V);
        sort(edges.begin(), edges.end(), compare());

        int cost = 0;
        for(Pair edge : edges){
            if(sets.findPar(edge.src) == sets.findPar(edge.nbr)){
                continue;
            }
            sets.union_set(edge.src,edge.nbr);
            cost += edge.wt;
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