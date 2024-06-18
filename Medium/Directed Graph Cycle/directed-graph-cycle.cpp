// DFS

// class Solution {
//   public:
//     bool dfs(int src, vector<int> adj[] , vector<int>& vis){
//         if(vis[src] == 1){
//             return true;
//         }
//         if(vis[src] == 2){
//             return false;
//         }
        
//         vis[src] = 1;//visiting the node for the fist time in preorder
//         for(int nbr : adj[src]){
//             if(dfs(nbr,adj,vis) == true){
//                 return true;
//             }
//         }
//         vis[src] = 2; //  visiting node in postorder
//         return false;
//     }
//     bool isCyclic(int V, vector<int> adj[]) {
//         vector<int>vis(V);// 0 -> unvisited, 1 -> preorder , 2 -> postorder
        
//         for(int i=0; i<V; i++){
//             if(vis[i] > 0){//already visited component then simply return
//                 continue;
//             }
//             if(dfs(i,adj,vis) == true){
//                 return true;
//             }
//         }
//         return false;
//     }
// };

// BFS

class Solution {
  public:
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>incoming(V,0);
        for(int i=0; i<V; i++){
            for(int node : adj[i]){
                incoming[node]++;
            }
        }
        
        vector<int>topo(V);
        int push = 0;
        int pop = 0;
        
        for(int i=0; i<V; i++){
            if(incoming[i] == 0){
                topo[push++] = i;
            }
        }
        
        while(pop < push && push < V){
            int src = incoming[pop++];
            for(int nbr : adj[src]){
                incoming[nbr]--;
                if(incoming[nbr] == 0){
                    topo[push++] = nbr;
                }
            }
        }
        if(push == V){
            return false;
        }
        else{
            return true;
        }
    }
};
