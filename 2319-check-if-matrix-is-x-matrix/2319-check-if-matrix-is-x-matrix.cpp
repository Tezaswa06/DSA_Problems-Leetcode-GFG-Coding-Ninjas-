class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        // int cols = mat[0].size();
        
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                int val = mat[row][col];
                if(row == col){
                    
                    if(val==0){
                        return false;
                    }
                }
                else if(row + col == n -1){
                    
                    if(val == 0){
                        return false;
                    }
                }else
                {
                    if(val != 0){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};