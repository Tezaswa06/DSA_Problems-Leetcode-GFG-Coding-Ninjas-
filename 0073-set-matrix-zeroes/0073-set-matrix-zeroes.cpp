class Solution {
public:
    void setRowsZero(vector<vector<int>>& matrix ,int row){
        for(int col=0;col<matrix[0].size();col++){
            matrix[row][col] = 0;
        }
    }
    void setColsZero(vector<vector<int>>& matrix,int col){
        for(int row=0;row<matrix.size();row++){
            matrix[row][col] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>>copy(matrix.size(),vector<int>(matrix[0].size()));

        for(int row=0;row<matrix.size();row++){
            for(int col=0;col<matrix[0].size();col++){
                copy[row][col] = matrix[row][col];
            }
        }

        for(int row=0;row<copy.size();row++){
            for(int col=0;col<copy[0].size();col++){
                if(copy[row][col]==0){
                    setRowsZero(matrix,row);
                    setColsZero(matrix,col);
                }
            }
        }

    }
};