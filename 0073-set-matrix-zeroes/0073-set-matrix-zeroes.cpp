class Solution {
public:
    // void setRowsZero(vector<vector<int>>& matrix ,int row){
    //     for(int col=0;col<matrix[0].size();col++){
    //         matrix[row][col] = 0;
    //     }
    // }
    // void setColsZero(vector<vector<int>>& matrix,int col){
    //     for(int row=0;row<matrix.size();row++){
    //         matrix[row][col] = 0;
    //     }
    // }
    // void setZeroes(vector<vector<int>>& matrix) {
    //     vector<vector<int>>copy(matrix.size(),vector<int>(matrix[0].size()));

    //     for(int row=0;row<matrix.size();row++){
    //         for(int col=0;col<matrix[0].size();col++){
    //             copy[row][col] = matrix[row][col];
    //         }
    //     }

    //     for(int row=0;row<copy.size();row++){
    //         for(int col=0;col<copy[0].size();col++){
    //             if(copy[row][col]==0){
    //                 setRowsZero(matrix,row);
    //                 setColsZero(matrix,col);
    //             }
    //         }
    //     }

    // }

    // Approach 2

    // void setZeroes(vector<vector<int>>& matrix) {
    //     vector<bool>Rows(matrix.size());
    //     vector<bool>Cols(matrix[0].size());

    //     // Queries to be run for Rows and Cols array to set true if we found 0 in the matrix

    //     for(int row=0;row<matrix.size();row++){
    //         for(int col=0;col<matrix[0].size();col++){
    //             if(matrix[row][col]==0){
    //                 Rows[row] = Cols[col] = true;
    //             }
    //         }
    //     }
    //     // updating each and every matrix element as we found that particular row or col to be true
    //             for(int row=0;row<matrix.size();row++){
    //                 for(int col=0;col<matrix[0].size();col++){
    //                     if(Rows[row]==true || Cols[col]==true){
    //                         matrix[row][col] = 0;
    //                     }
    //                 }
    //            }
    // }

    // Approach 3

    void setZeroes(vector<vector<int>>& matrix){
        bool zerothrow = false;
        bool zerothcol = false;

        for(int row=0;row<matrix.size();row++){
            for(int col=0;col<matrix[0].size();col++){
                if(matrix[row][col]==0){
                    matrix[0][col] = matrix[row][0] = 0;
                if(row == 0){
                    zerothrow = true;
                }
                if(col == 0){
                    zerothcol = true;
                }
                }
            }
        }
        for(int row=1;row<matrix.size();row++){
            for(int col=1;col<matrix[0].size();col++){
                if(matrix[0][col]==0 || matrix[row][0]==0){
                    matrix[row][col] = 0;
                }
            }
        }
        if(zerothrow == true){
            for(int col=0;col<matrix[0].size();col++){
                matrix[0][col] = 0;
            }
        }
        if(zerothcol == true){
            for(int row=0;row<matrix.size();row++){
                matrix[row][0] = 0;
            }
        }
    }
};