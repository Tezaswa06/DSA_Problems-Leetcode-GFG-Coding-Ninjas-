class Solution {
public: 

    bool iswinner(vector<vector<char>> board,int row,int col,char ch){
        // checking the entire row
        if(board[row][0] == ch && board[row][1] == ch && board[row][2] == ch){
            return true;
        }
        // checking the entire col
        if(board[0][col]==ch && board[1][col] ==ch && board[2][col]==ch){
            return true;
        }
        // checking if diagonal contains same or not
        if(board[0][0]==ch && board[1][1]==ch && board[2][2]==ch){
            return true;
        }
        // checnking th other diagonal
        if(board[0][2] == ch && board[1][1]==ch && board[2][0]==ch){
            return true;
        }
        return false;
    }
    string tictactoe(vector<vector<int>>& moves) {
        // created a board of tic tac toe 
        vector<vector<char>>board(3,vector<char>(3));

        char ch = 'X';

        for(vector<int>move :moves){
            int row = move[0];
            int col = move[1];
            board[row][col] = ch;

            if(iswinner(board,row,col,ch)==true){
                if(ch == 'X'){
                    return "A";
                }
                else{
                    return "B";
                }
            }
            if(ch == 'X'){
                ch = 'O';
            }
            else{
                ch = 'X';
            }
        }

        if(moves.size()==9){
            return "Draw";
        }
        else{
            return "Pending";
        }
    }
};