//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Graph {
public:
    int n;
    vector<vector<char>> adj;
    
    Graph(int n) {
        this->n = n;
        adj.resize(n);
    }
    
    void addEdge(char src, char dest) {
        adj[src - 'a'].push_back(dest);
    }
};

class Solution {
public:
    string topo = "";
    
    void dfs(Graph& g, char src, vector<bool>& vis) {
        if (vis[src - 'a']) {
            return;
        }
        vis[src - 'a'] = true;
        
        for (char nbr : g.adj[src - 'a']) {
            dfs(g, nbr, vis);
        }
        topo.push_back(src);
    }
    
    string findOrder(string dict[], int words, int letters) {
        Graph g(letters);
        
        for (int w = 0; w < words - 1; w++) {
            int l = min(dict[w].size(), dict[w + 1].size()); 
            for (int i = 0; i < l; i++) {
                char ch1 = dict[w][i];
                char ch2 = dict[w + 1][i];
                
                if (ch1 != ch2) {
                    g.addEdge(ch1, ch2);
                    break;
                }
            }
        }
        
        vector<bool> vis(letters, false);
        for (int i = 0; i < letters; i++) {
            if (!vis[i]) {
                dfs(g, i + 'a', vis);
            }
        }
        
        reverse(topo.begin(), topo.end());
        return topo;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends