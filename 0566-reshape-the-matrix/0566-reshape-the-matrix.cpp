
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int originalRows = mat.size();
        int originalCols = mat[0].size();

        if (originalRows * originalCols != r * c) {
            return mat;
        }

        vector<vector<int>> answer(r,vector<int>(c));
        int originalRow = 0;
        int originalCol = 0;

        for (int row = 0; row < r; row++) {
            for (int col = 0; col < c; col++) {
                answer[row][col] = mat[originalRow][originalCol];
                originalCol++;
            
            if (originalCol == originalCols) {
                originalCol = 0;
                originalRow++;
            }
        }
        }
        return answer;
    }
};