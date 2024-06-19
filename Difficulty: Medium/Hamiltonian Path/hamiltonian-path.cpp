//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Graph{
    public:
    
    int n;
    vector<int>* adj;
    
    Graph(int n){
        this -> n = n;
        adj = new vector<int>[n];
    }
    
    void addEdge(int src, int dest){
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }
};
class Solution
{
    public:
    int countVisited(vector<bool>& vis){
        int count = 0;
        for(bool v : vis){
            if(v == true){
                count++;
            }
        }
        return count;
    }
    bool dfs(int src,Graph g, vector<bool>& vis){
        if(vis[src] == true){
            return false;
        }
        vis[src] = true;
        if(countVisited(vis) == g.n){
            return true;
        }
        for(int nbr : g.adj[src]){
            if(dfs(nbr,g,vis) == true){
                return true;
            }
        }
        vis[src] = false;//backtracking so that if the path which we choose is not correct then we can backtrack from that path and can choose different path
        return false;
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        Graph g(N);
        for(const vector<int>edge : Edges){
            g.addEdge(edge[0] - 1, edge[1] - 1);
        }
        
        vector<bool>vis(N,false);
        for(int i=0; i<N; i++){
            if(dfs(i,g,vis) == true){
                return true;
            }
        }
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends