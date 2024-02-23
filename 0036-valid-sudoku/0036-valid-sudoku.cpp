class Solution {
public:
    bool isvalidRow(vector<vector<char>>& board,int row){
        vector<int>frequency(10);
        for(int col=0;col<9;col++){
            int val = board[row][col] - '0';
            if(board[row][col]=='.'){
                continue;
            }
            frequency[val]++;
            if(frequency[val]>1){
                return false;
            }
        }
        return true;
    }
    bool isvalidCol(vector<vector<char>>& board,int col){
        vector<int>frequency(10);
        for(int row=0;row<9;row++){
            int val = board[row][col] - '0';
            if(board[row][col]=='.'){
                continue;
            }
            frequency[val]++;
            if(frequency[val]>1){
                return false;
            }
        }
        return true;
    }
    bool isvalidGrid(vector<vector<char>>& board,int row,int col){
        vector<int>frequency(10);
        for(int r=row;r<row+3;r++){
            for(int c=col;c<col+3;c++){
                int val = board[r][c] - '0';
                if(board[r][c]=='.'){
                    continue;
                }
                frequency[val]++;
                if(frequency[val]>1){
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
         
        for(int row=0;row<9;row++){
            if(isvalidRow(board,row)==false){
                return false;
            }
        }
        for(int col=0;col<9;col++){
            if(isvalidCol(board,col)==false){
                return false;
            }
        }
        for(int row=0;row<9;row=row+3){
            for(int col=0;col<9;col=col+3){
                if(isvalidGrid(board,row,col)==false){
                    return false;
                }
            }
        }
        return true;
    }
};