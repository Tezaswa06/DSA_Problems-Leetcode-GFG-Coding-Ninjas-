class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>answer;
        for(int row = 0;row<matrix.size();row++){
            int min = 0;
            for(int col = 0;col<matrix[0].size();col++){
                if(matrix[row][col]<matrix[row][min]){
                    min = col;
                }
            }
            int max = 0;
            for(int r = 0;r<matrix.size();r++){
                if(max < matrix[r][min]){
                    max = matrix[r][min];
                }
            }
            if(max == matrix[row][min]){
                answer.push_back(max);
            }
        }
        return answer;
    }
};