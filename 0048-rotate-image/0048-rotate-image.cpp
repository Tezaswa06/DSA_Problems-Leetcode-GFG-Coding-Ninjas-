class Solution {
public:
    void transpose(vector<vector<int>>& matrix,int n){

        for(int row=0;row<n;row++){
            for(int col=row;col<n;col++){
                swap(matrix[col][row],matrix[row][col]);
            }
        }
    }
    void reverse(vector<vector<int>>& matrix,int n){
        for(int row=0;row<n;row++){
            int left = 0;
            int right = n-1;
            while(left<right){
                swap(matrix[row][left],matrix[row][right]);
                left++;
                right--;
            }
        }

    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        transpose(matrix,n);
        reverse(matrix,n); 
    }
};