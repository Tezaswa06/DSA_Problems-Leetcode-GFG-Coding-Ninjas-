class Solution {
public:
    vector<int>disc;
    vector<int>low;
    int time = 0;
    vector<vector<int>>bridges;

    void dfs(int src, int parent, vector<vector<int>>& adj){
        disc[src] = low[src] = time;
        time++;

        for(auto nbr : adj[src]){
            if(nbr == parent){
                continue;// nbr se call lagaya hai to uske parent pe hum nhi jayenge
            }
            if(disc[nbr] >= 0){
                // back edge (already visited nbr)
                low[src] = min(low[src] , disc[nbr]);
            }
            else{
                dfs(nbr,src,adj);// unvisited nbr

                if(low[nbr] > disc[src]){
                    vector<int>bridge;
                    bridge.push_back(src);
                    bridge.push_back(nbr);
                    bridges.push_back(bridge);
                }
                low[src] = min(low[src],low[nbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        disc.resize(n,-1);
        low.resize(n);

        vector<vector<int>>adj(n);
        for(auto edge : connections){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(0,-1,adj);
        return bridges;
    }
};