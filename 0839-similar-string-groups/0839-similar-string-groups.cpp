class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n, -1);
        rank.resize(n, 1);
    }

    void union_set(int a, int b) {
        int pa = findPar(a);
        int pb = findPar(b);

        if (pa == pb) return; // Prevent cycles

        if (rank[pa] > rank[pb]) {
            parent[pb] = pa;
            rank[pa] += rank[pb];
        } else {
            parent[pa] = pb;
            rank[pb] += rank[pa];
        }
    }

    int findPar(int a) {
        if (parent[a] == -1) {
            return a;
        }
        return parent[a] = findPar(parent[a]); // Path compression
    }
};

class Solution {
public:
    bool isSimilar(string a, string b) {
        int count = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                count++;
            }
        }
        return count == 2 || count == 0; // Similar if exactly 2 positions differ or they are identical
    }

    int numSimilarGroups(vector<string>& strs) {
        DSU sets(strs.size());

        for (int i = 0; i < strs.size(); ++i) {
            for (int j = i + 1; j < strs.size(); ++j) {
                if (isSimilar(strs[i], strs[j])) {
                    sets.union_set(i, j);
                }
            }
        }

        int groups = 0;
        for (int i = 0; i < strs.size(); ++i) {
            if (sets.findPar(i) == i) {
                ++groups;
            }
        }
        return groups;
    }
};