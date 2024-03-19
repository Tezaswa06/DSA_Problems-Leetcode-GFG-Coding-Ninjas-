class Solution {
public:
    vector<vector<int>> ways;

    void printWays(vector<int>& coins,int target,int index,vector<int>& output){
        if(target < 0){
            return ;
        }
        if(index == coins.size()){
            if(target == 0){
                ways.push_back(output);
            }
            return ;
        }
        
        output.push_back(coins[index]);
        printWays(coins,target - coins[index],index + 1,output);
        output.pop_back();

        if(output.size() > 0 && output[output.size()-1] == coins[index]){
            return;
        }
        printWays(coins,target,index + 1,output);
    }
    vector<vector<int>> combinationSum2(vector<int>& coins, int target) {
        sort(coins.begin(),coins.end());
        vector<int>output;
        printWays(coins,target,0,output);
        return ways;
    }
};