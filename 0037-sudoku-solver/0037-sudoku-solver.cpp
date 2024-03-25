class Solution {
public:
    vector<vector<char>> result;
     
    bool isSafe(vector<vector<char>>& board,int row,int col,char ch){
        
        for(int c = 0 ; c < 9 ; c++){
            if(board[row][c] == ch){
                return false;
            }
        }
        for(int r = 0 ; r < 9 ; r++){
            if(board[r][col] == ch){
                return false;
            }
        }
        row = (row / 3) * 3;
        col = (col / 3) * 3;
        for(int r = 0 ; r < 3 ; r++){
            for(int c = 0 ; c < 3 ; c++){
                if(board[row + r][col + c] == ch){
                    return false;
                }
            }
        }
        return true;
    }
    void sudoku(vector<vector<char>>& board,int row,int col){
        if(row == 9){
            result = board;
            return ;
        }
        if(board[row][col] != '.'){
            sudoku(board , (col < 8) ? row : row + 1,(col < 8) ? col + 1 : 0);
            return;
        }
        for(char ch = '1' ; ch <= '9' ; ch++){
            if(isSafe(board,row,col,ch) == false){
                continue;
            }
            board[row][col] = ch;
            sudoku(board , (col < 8) ? row : row + 1,(col < 8) ? col + 1 : 0);
            if(!result.empty()){
                return ;
            }
            board[row][col] = '.';
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        sudoku(board , 0 , 0);

    }
};