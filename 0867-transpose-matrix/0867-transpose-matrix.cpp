class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
       vector<vector<int>> transposematrix(matrix[0].size(), vector<int>(matrix.size()));
        for(int row=0;row<matrix.size();row++){
            for(int col=0;col<matrix[0].size();col++){
                transposematrix[col][row] = matrix[row][col];
            }
        }
        return transposematrix;
    }
};