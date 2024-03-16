class Solution {
public:

    int maxgoldamount = 0;

    void goldpaths(vector<vector<int>>& grid,int row,int col,int goldsum){
       
        if(row < 0 || col < 0 || row == grid.size() || col == grid[0].size()){
            return ;
        }
        if(grid[row][col] == 0){
            return ;
        }
        
        int currgold = grid[row][col];
        goldsum += currgold;

        maxgoldamount = max(maxgoldamount,goldsum);

        grid[row][col] = 0;

        goldpaths(grid,row-1,col,goldsum);
        goldpaths(grid,row+1,col,goldsum);
        goldpaths(grid,row,col-1,goldsum);
        goldpaths(grid,row,col+1,goldsum);

        grid[row][col] = currgold;
        goldsum -= currgold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        
        for(int row = 0;row < grid.size();row++){
            for(int col = 0;col < grid[0].size();col++){
                int goldsum = 0;
                if(grid[row][col]!=0){
                    goldpaths(grid,row,col,goldsum);
                }
      
            }
        }
        return maxgoldamount;
    }
};