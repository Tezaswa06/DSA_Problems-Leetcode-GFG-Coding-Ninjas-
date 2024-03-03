class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size()-1;
        // we are checking from the top right so we have to check till bottom wall for the row and right wall for the col
        while(row < matrix.size() && col >= 0){
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]<target){
                row++; // discarding the row if the value of matrix is less thank the target
            }
            else{
                col--; // discarding the col if the value of the matrix is more than the tarrget
            }
        }
        return false;;
    }
};