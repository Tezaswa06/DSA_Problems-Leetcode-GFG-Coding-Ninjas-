class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int Rows = matrix.size();
        int Cols = matrix[0].size();

        for(int diag=1-Cols;diag<=Rows-1;diag++){
            int row = (diag<=0) ? 0 : diag;
            int col = (diag<=0) ? -diag : 0;

            int val = matrix[row][col];

            while(row<Rows && col<Cols){
                if(matrix[row][col]!=val){
                    return false;
                }
                row++;
                col++;
            }
        }
        return true;
    }
};