class Solution {
public:
    vector<vector<int>> ways;

    void printPaths(vector<int>& nums,vector<int>& output,vector<bool>& visited){
        if(output.size() == nums.size()){
            ways.push_back(output);
            return ;
        }
        for(int index = 0 ; index < nums.size() ; index++){
            if(visited[index] == true){ // if the current index is true then then that index will bw skipped
                continue;
            }
            output.push_back(nums[index]);
            visited[index] = true;

            printPaths(nums,output,visited); // here we are only rearranging the items so we want all the items that is why there is no no choice during recursion call

            output.pop_back();
            visited[index] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>visited(nums.size()); // this will tell if the index is visited or not if visited then we will not visit it again
        vector<int>output;
        printPaths(nums,output,visited);
        return ways;
    }
};