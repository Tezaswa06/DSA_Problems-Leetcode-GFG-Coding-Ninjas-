class Solution {
public:
    int startRow = -1;
    int startCol = -1;
    int endRow = -1;
    int endCol = -1;

    int countPaths(vector<vector<int>>& grid,int row,int col,int freecells){
        if(row < 0 || col < 0 || row == grid.size() || col == grid[0].size()){
            return 0;
        }
        if(grid[row][col] == -2 || grid[row][col] == -1){
            return 0;
        }

        if(row == endRow && col == endCol){
            if(freecells == 0){
                return 1;
            }
            else{
                return 0;
            }
        }

        grid[row][col] = -2;

        int path = 0;

        path += countPaths(grid,row - 1,col,freecells - 1);
        path += countPaths(grid,row + 1,col,freecells - 1);
        path += countPaths(grid,row,col - 1,freecells - 1);
        path += countPaths(grid,row,col + 1,freecells - 1);

        grid[row][col] = 0;

        return path;

    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int freecells = 1; // we will count the starting index also

        for(int row = 0;row < grid.size();row++){
            for(int col = 0;col < grid[0].size();col++){
                if(grid[row][col] == 0){
                    freecells++;
                }
                if(grid[row][col] == 1){
                    startRow = row;
                    startCol = col;
                }
                if(grid[row][col] == 2){
                    endRow = row;
                    endCol = col;
                }
            }
        }
        return countPaths(grid,startRow,startCol,freecells);
    }
}; 