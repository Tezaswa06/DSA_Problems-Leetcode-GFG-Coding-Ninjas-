class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int k) {
        int n = image.size();
        int m = image[0].size();
        map<pair<int,int>,pair<int,int>>mp;// A map to keep track of the accumulated sum and count of values for each cell
        for(int i=0; i<n-2; i++){
            for(int j=0; j<m-2; j++){
                int sum = 0;
                bool check = true;
                for(int x=i; x<i+3; x++){
                    for(int y=j; y<j+3; y++){
                        sum += image[x][y];
                        if(x+1 < i+3){// these if loops are for checking if the current cell lies in our regieon or not
                            if(abs(image[x][y] - image[x+1][y]) > k){
                                check = false;
                                break;
                            }
                        }
                        if(y+1 < j+3){
                            if(abs(image[x][y] - image[x][y+1]) > k){
                                check = false;
                                break;
                            }
                        }
                    }
                    if(check == false){
                        break;
                    }
                }
                if(check == false){
                    continue;
                }
                sum = sum/9;// calculating the average of each cell
                for(int x=i; x<i+3; x++){
                    for(int y=j; y<j+3; y++){
                        if(mp.find({x,y}) != mp.end()){// If the cell is already in the map, add the new sum and increment the count
                            pair<int,int>p = mp[{x,y}];
                            mp[{x,y}] = {p.first+sum,p.second+1};
                        }
                        else{
                            mp[{x,y}] = {sum,1};
                        }
                    }
                }
            }
        }
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mp.find({i,j}) == mp.end()){// If the cell is not in the map, use the original image value
                    ans[i][j] = image[i][j];
                    continue;
                }
                pair<int,int>p = mp[{i,j}];// Otherwise, calculate the average and set it in the result grid
                int sum = p.first/p.second;
                ans[i][j] = sum;
            }
        }
        return ans;
    }
};