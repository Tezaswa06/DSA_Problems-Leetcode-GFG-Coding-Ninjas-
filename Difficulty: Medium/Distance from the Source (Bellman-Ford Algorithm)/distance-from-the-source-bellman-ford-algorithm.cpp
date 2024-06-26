//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// the below code will run if no edge weight cycle exist

// class Solution {
//   public:
    
//     vector<int> bellman_ford(int V, vector<vector<int>>& edges, int src) {
//         int inf = 1e8;
//         vector<int>dist(V,inf);
//         dist[src] = 0;
        
//         for(int i=1; i<V; i++){
//             for(auto edge : edges){
//                 int a = edge[0];
//                 int b = edge[1];
//                 int wt = edge[2];
                
//                 if(dist[a] == inf){
//                     continue;
//                 }
//                 dist[b] = min(dist[a] + wt, dist[b]);
//             }
//         }
//         return dist;
//     }
// };


// the below code will run if negative edge weight cycle exist 
class Solution {
  public:
    
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int src) {
        int inf = 1e8;
        vector<int>dist(V,inf);
        dist[src] = 0;
        
        for(int i=1; i<V; i++){
            for(auto edge : edges){
                int a = edge[0];
                int b = edge[1];
                int wt = edge[2];
                
                if(dist[a] == inf){
                    continue;
                }
                dist[b] = min(dist[b], dist[a] + wt);
            }
        }
        for(auto edge : edges){
            int a = edge[0];
            int b = edge[1];
            int wt = edge[2];
            
            if(dist[a] == inf){
                continue;
            }
            if(dist[a] + wt < dist[b]){
                return {-1};
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends