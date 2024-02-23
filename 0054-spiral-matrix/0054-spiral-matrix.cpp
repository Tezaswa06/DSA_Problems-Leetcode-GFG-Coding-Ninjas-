class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>spiral;
        int firstrow = 0;
        int firstcol = 0;
        int lastrow = matrix.size()-1;
        int lastcol = matrix[0].size()-1;

        while(true)// as we don't know till when do we have to run or the corner case is not yet defined propely
        {
            // first we will check for the top wall(left to right)
            for(int col=firstcol;col<=lastcol;col++){
                spiral.push_back(matrix[firstrow][col]);
            }
            firstrow++; // as we don't want redundancy or the values to get repeated so after getting the entire first row we have skipped the first row
            
            if(firstrow>lastrow){
                break;
            }

            // here we will check for the right wall( top to bottom)
            for(int row=firstrow;row<=lastrow;row++){
                spiral.push_back(matrix[row][lastcol]);
            }
            lastcol--; // same as we have done above in the firstrow

            if(firstcol>lastcol){
                break;
            }

            // here we are checking bottom wall (right to left)
            for(int col=lastcol;col>=firstcol;col--){
                spiral.push_back(matrix[lastrow][col]);
            }
            lastrow--;

            if(firstrow>lastrow){
                break;
            }

            // here we are checking for the right wall(bottom to top)
            for(int row=lastrow;row>=firstrow;row--){
                spiral.push_back(matrix[row][firstcol]);
            }
            firstcol++;

            if(firstcol>lastcol){
                break;
            }
        }
        return spiral;
    }
};