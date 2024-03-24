class Solution {
public:
    vector<vector<string>> ways;
    bool isQueenSafe(vector<vector<bool>>& chess,int row,int col,int n){
        for(int r = row ; r >= 0 ; r--){
            if(chess[r][col] == true){
                return false;
            }
        }
        for (int r = row, c = col; r >= 0 && c >= 0; --r, --c) {
            if (chess[r][c]) return false;
        }
        
        // Check upper right diagonal
        for (int r = row, c = col; r >= 0 && c < n; --r, ++c) {
            if (chess[r][c]) return false;
        }
        
        return true;
    }
    void updateChess(vector<vector<bool>>& chess,int n){
        vector<string>output;
        for(int row = 0;row < n;row++){
            string str = "";
            for(int col = 0;col < n;col++){
                if(chess[row][col] == true){
                    str += 'Q';
                }
                else{
                    str += '.';
                }
            }
            output.push_back(str);
        }
        ways.push_back(output);
    }
    void nQueens(vector<vector<bool>>& chess , int row, int n){
        if(row == n){
            updateChess(chess,n);
            return;
        }
        for(int col = 0;col < n;col++){
            if(isQueenSafe(chess,row,col,n) == false){
                continue;
            }
            chess[row][col] = true;
            nQueens(chess,row + 1,n);
            chess[row][col] = false;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>>chess(n,vector<bool>(n));
        nQueens(chess,0,n);
        return ways;
    }
};