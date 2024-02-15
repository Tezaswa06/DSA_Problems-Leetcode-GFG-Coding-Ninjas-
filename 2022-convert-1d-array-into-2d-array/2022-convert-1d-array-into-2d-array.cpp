class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>matrix(m,vector<int>(n,0));
    
        if(m*n!=original.size()){
            return {};
        }
        int index = 0;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                matrix[row][col] = original[index++];
            }
        }
        return matrix;
    }
};