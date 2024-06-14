class Graph{
    public:
    int n; //no of vertices
    vector<int>* adj;// creating adjacency list

    Graph(int n){// constructor to initialise graph
        this -> n = n;
        adj = new vector<int>[n];
    }

    void addEdge(int src, int dest){// adding edges to the nodes(undirected)
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }

    bool hasPath(int src,int dest,vector<bool>& vis){
        if(src == dest){
            return true;
        }
        if(vis[src] == true){// menas if in any node we already visited then return false; so that we can escape infinite loop
            return false;
        }

        vis[src] = true;// as we started from any node then mark it as visited right away
        for(int nbr : adj[src]){
            if(hasPath(nbr,dest,vis) == true){
                return true;
            }
        }
        return false;
    }

};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        Graph g(n);// creating graph with n nodes    
        for(const vector<int>edge : edges){
            g.addEdge(edge[0],edge[1]);
        }
        vector<bool>vis(n,false);
        return g.hasPath(source,destination,vis);
    }
};