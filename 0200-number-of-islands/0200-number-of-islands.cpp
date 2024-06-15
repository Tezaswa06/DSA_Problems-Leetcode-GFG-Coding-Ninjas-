class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col){
        if(row == -1 || col == -1 || row >= grid.size() || col >= grid[0].size()){
            return;
        }
        if(grid[row][col] == '0' || grid[row][col] == '2'){
            return;
        }

        grid[row][col] = '2';

        dfs(grid,row + 1,col);
        dfs(grid,row,col + 1);
        dfs(grid,row - 1,col);
        dfs(grid,row,col - 1);

    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for(int row=0; row<grid.size(); row++){
            for(int col=0; col < grid[0].size(); col++){
                if(grid[row][col] == '1'){
                    islands++;
                    dfs(grid,row,col);
                }
            }
        }
        return islands;
    }
};