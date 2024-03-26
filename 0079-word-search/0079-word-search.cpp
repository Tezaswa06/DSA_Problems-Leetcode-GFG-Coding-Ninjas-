class Solution {
public:
    // {top , bottom , left , right}
    vector<int>dr = {-1,+1,0,0};
    vector<int>dc = {0,0,-1,+1};

    bool search(vector<vector<char>>& board,string word,int row,int col ,int index){
        if(index == word.size()){
            return true;
        }
        if(row < 0 || col < 0 || row == board.size() || col == board[0].size()){
            return false;
        }
        if(board[row][col] != word[index]){
            return false;
        }
        for(int d = 0 ; d < 4 ; d++){
            board[row][col] = '#';
            bool ans = search(board,word,row+dr[d],col+dc[d],index+1);
            if(ans == true){
                return true;
            }
            board[row][col] = word[index];
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int row = 0 ; row < board.size() ; row++){
            for(int col = 0 ; col < board[0].size() ; col++){
                bool ans = search(board,word,row,col,0);
                if(ans == true){
                    return true;
                }
            }
        }
        return false;
    }
};