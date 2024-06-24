struct Pair{
    int row;
    int col;
    int val;
    int dist;

    Pair(int row,int col,int val,int dist){
        this -> row = row;
        this -> col = col;
        this -> val = val;
        this -> dist = dist;
    }
};
class Compare{
    public:

    bool operator()(auto a, auto b){
        return a.dist > b.dist;
    }
};

class Solution {
public:
    vector<int>dr = {0,0,1,-1};
    vector<int>dc = {1,-1,0,0};

    int minimumEffortPath(vector<vector<int>>& mat) {
        priority_queue<Pair,vector<Pair>,Compare>q;
        q.push(Pair(0,0,mat[0][0],0));

        while(q.size() > 0){
            Pair p = q.top();
            q.pop();

            if(p.row == mat.size() - 1 && p.col == mat[0].size() - 1){
                return p.dist;
            }

            if(mat[p.row][p.col] == -1){
                continue;
            }
            for(int d=0; d<4; d++){
                int nr = p.row + dr[d];
                int nc = p.col + dc[d];

                if(nr < 0 || nc < 0 || nr >= mat.size() || nc >= mat[0].size()){
                    continue;
                }
                int nd = max(p.dist,abs(mat[nr][nc] - mat[p.row][p.col]));
                q.push(Pair(nr,nc,mat[nr][nc],nd));
            }
            mat[p.row][p.col] = -1;// marked visited
        }
        return 0;
    }
};