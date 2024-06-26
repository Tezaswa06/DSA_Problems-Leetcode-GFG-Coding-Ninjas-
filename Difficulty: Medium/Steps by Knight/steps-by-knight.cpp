//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct Pair{
    int r;
    int c;
    int dist;
    
    Pair(int r, int c, int dist){
        this -> r = r;
        this -> c = c;
        this -> dist = dist;
    }
};
class Solution 
{
    public:
    int bfs(int i, int j, int n, int m,vector<vector<int>>& adj, int size,vector<vector<bool>>& vis){
        queue<Pair>q;
        q.push(Pair(i,j,0));
        
        
        vis[i][j] = true;
        
        while(q.size() > 0){
            Pair p = q.front();
            q.pop();
            
            if(p.r == n && p.c == m){
                return p.dist;
            }
            for(auto it : adj){
                int row = p.r + it[0];
                int col = p.c + it[1];
                
                if(row >= 1 && col >= 1 && row <= size && col <= size && !vis[row][col]) {
                    vis[row][col] = true;
                    q.push(Pair(row, col, p.dist + 1));
                }
            }
        }
        return -1;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    vector<vector<int>>adj = {{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2}};
	    vector<vector<bool>>vis(N+1,vector<bool>(N+1,false));
	    
	    int ans = bfs(KnightPos[0],KnightPos[1],TargetPos[0],TargetPos[1],adj,N,vis);
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends