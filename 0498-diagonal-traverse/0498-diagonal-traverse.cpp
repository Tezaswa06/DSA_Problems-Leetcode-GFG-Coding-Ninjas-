class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int Rows = mat.size();
        int Cols = mat[0].size();
        vector<int>answer(Rows*Cols);
        int index = 0;

        for(int diag=0;diag<=Rows+Cols-2;diag++){
            if(diag%2==1){
                int row = (diag<Cols) ? 0 : diag - Cols + 1;
                int col = (diag<Cols) ? diag : Cols - 1;

                while(row<Rows && col>=0){
                    answer[index++] = mat[row][col];
                    row++;
                    col--;
                }
            }
            else{
                int row = (diag<Rows) ? diag : Rows - 1;
                int col = (diag<Rows) ? 0 : diag - Rows + 1;

                while(row>=0 && col<Cols){
                    answer[index++] = mat[row][col];
                    col++;
                    row--;
                }
            }
        }
        return answer;
    }
};