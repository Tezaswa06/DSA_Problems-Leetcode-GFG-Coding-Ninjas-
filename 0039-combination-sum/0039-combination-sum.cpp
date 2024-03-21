class Solution {
public:
    vector<vector<int>>ways;

    void printWays(vector<int>& coins, int index,int target, vector<int>& output){
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
        printWays(coins,index,target-coins[index],output); // if chpoice is yes then also we will be taking the same index so that it can come for infinite time to satisfy the target
        output.pop_back();

        printWays(coins,index+1,target,output);
    }
    vector<vector<int>> combinationSum(vector<int>& coins, int target) {
        vector<int>output;
        printWays(coins,0,target,output);
        return ways;
    }
};