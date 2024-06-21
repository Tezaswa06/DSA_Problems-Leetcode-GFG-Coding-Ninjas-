//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    bool canColor(int src,int color,bool mat[101][101],vector<int>& vis,int n){
        for(int nbr=0; nbr<n; nbr++){
            if(mat[src][nbr] == false){// menas there is no node between his source and its neighbours
                continue;
            }
            if(vis[nbr] == color){// means source ke nbr ke paas already vo color hai
                return false;
            }
        }
        return true;
    }
    bool helper(int src,int m,bool mat[101][101],vector<int>& vis, int n){
        if(src == n){// yhs pe src ek ek kar ke node pe jaa rha hai usko isse farak nhi padta ki nodes src aur src + 1 ke beech ahi ki nhi
                return true;
        }
        
        for(int c=1; c<=m; c++){// yha pe c nof of colors ko denote kar rha hai
            if(canColor(src,c,mat,vis,n) == false){
                continue;
            }
            vis[src] = c;
            if(helper(src + 1,m,mat,vis,n) == true){
                return true;
            }
            
            vis[src] = 0;// agar us node pe hum koi bhi color nhi kar paa rahe hai m tak to hum backtrack kar ke pichle node ke color ko change karenge
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
       vector<int>vis(n);
       return helper(0,m,graph,vis,n);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends