// basically we have to detect cycle so the below approach we have done is through khan's algo of topological sort through bfs

// class Graph{
// public:
//     int n;
//     vector<int>* adj;

//     Graph(int n){
//         this -> n = n;
//         adj = new vector<int>[n];
//     }

//     // unweighted , directed
//     void addEdge(int src, int dest){
//         adj[src].push_back(dest);
//     }
// };

// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         Graph g(numCourses);

//         for(const vector<int>edge : prerequisites){
//             g.addEdge(edge[1] , edge[0]);
//         }

//         vector<int>incoming(numCourses,0);
//         for(const vector<int>node : prerequisites){
//             incoming[node[0]]++;
//         }

//         vector<int>topo(numCourses);// treating this array as queue how we dry runned it in copy
//         int push = 0;
//         int pop = 0;

//         for(int i=0; i<numCourses; i++){
//             if(incoming[i] == 0){
//                 topo[push++] = i;
//             }
//         }

//         while(pop < push && push < numCourses){
//             int src = topo[pop++];
//             for(int nbr : g.adj[src]){
//                 incoming[nbr]--;
//                 if(incoming[nbr] == 0){
//                     topo[push++] = nbr;
//                 }
//             }
//         }
//         if(push == numCourses){
//             return true;// topological sort exist -> courses finished
//         }
//         return false;// topological sort does not exist -> courses are not finished (cycle detected)
//     }
// };

// now in the below approach we will be doing it with dfs approach of graph coloring to detect cycle in the graph
class Graph{
public:
    int n;
    vector<int>* adj;

    Graph(int n){
        this -> n = n;
        adj = new vector<int>[n];
    }

    // unweighted , directed
    void addEdge(int src, int dest){
        adj[src].push_back(dest);
    }
    bool dfs(int src, vector<int>& vis){
        if(vis[src] == 1){
            return true; // cycle detected while going preorder
        }
        if(vis[src] == 2){
            return false;// indicates visiting already visited array 
        }
        vis[src] = 1;
        for(int nbr : adj[src]){
            if(dfs(nbr,vis) == true){
                return true;
            }
        }
        vis[src] = 2;// visiting node in postorder
        return false;
    }
};
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g(numCourses);
        for(const vector<int>edge : prerequisites){
            g.addEdge(edge[1],edge[0]);
        }

        vector<int>vis(numCourses);
        for(int i=0; i<numCourses; i++){
            if(vis[i] > 0){
                continue;
            }
            if(g.dfs(i,vis) == true){
                return false;
            }
        }
        return true;
    }
};