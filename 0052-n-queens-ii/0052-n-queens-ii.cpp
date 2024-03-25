class Solution {
public:

    bool isQueenSafe(vector<vector<bool>>& chess , int row , int col ,int n){

        for(int r = row ; r >= 0 ; r-- ){
            if(chess[r][col] == true){
                return false;
            }
        }
        for(int r=row,c=col ; r>=0 && c>=0;r--,c--){
            if(chess[r][c] == true){
                return false;
            }
        }
        for(int r=row,c=col;r>=0 && c<n;r--,c++){
            if(chess[r][c] == true){
                return false;
            }
        }
        return true;
    }
    int nQueens(vector<vector<bool>>& chess,int row,int n){
        if(row == n){
            return 1;
        }
        int sum = 0;
        for(int col = 0; col < n ; col++){
            if(isQueenSafe(chess,row,col,n) == false){
                continue;
            }
            chess[row][col] = true;
            sum += nQueens(chess,row+1,n);
            chess[row][col] = false;
        }
        return sum;
    }
    int totalNQueens(int n) {
        vector<vector<bool>>chess(n,vector<bool>(n));
        return nQueens(chess,0,n);
    }
};