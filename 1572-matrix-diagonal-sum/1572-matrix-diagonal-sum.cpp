class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int primarydiagonalsum = 0;
        int secondarydiagonalsum = 0;
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(row == col){
                    int val = mat[row][col];
                    primarydiagonalsum+=val;
                }
                else if(row + col == cols -1){
                    int val = mat[row][col];
                    secondarydiagonalsum +=val;
                }
            }
        }
        
        return primarydiagonalsum+secondarydiagonalsum;
    }
};