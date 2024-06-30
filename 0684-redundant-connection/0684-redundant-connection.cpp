class DSU{
    public:

    vector<int>parent;
    vector<int>rank;

    DSU(int n){
        parent.resize(n,-1);
        rank.resize(n,1);
    }

    void union_set(int a, int b){
        int pa = findpar(a);
        int pb = findpar(b);

        if(pa == pb){
            return;
        }
        if(rank[pa] > rank[pb]){
            parent[pb] = pa;
            rank[pa] += rank[pb];
        }
        else{
            parent[pa] = pb;
            rank[pb] += rank[pa];
        }
    }
    int findpar(int a){
        if(parent[a] == -1){
            return a;
        }
        return parent[a] = findpar(parent[a]);
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU sets(1001);

        for(auto edge : edges){
            int a = edge[0];
            int b = edge[1];
            if(sets.findpar(a) == sets.findpar(b)){
                return edge;
            }
            sets.union_set(a,b);
        }
        return {};
    }
};