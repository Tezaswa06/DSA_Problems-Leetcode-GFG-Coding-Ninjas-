class Solution {
public:
    vector<vector<int>>paths;
    void dfs(int src, int dest, vector<vector<int>>graph,vector<int>path){
        path.push_back(src);
        if(src == dest){
            paths.push_back(path);
        }

        for(int nbr : graph[src]){
            dfs(nbr,dest,graph,path);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();//it will give no of nodes which is stored in column of 2d graph array
        vector<int>path;// this will store each path from src to dest
        dfs(0, n - 1, graph, path);
        return paths;    
    }
};