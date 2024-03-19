class Solution {
public:

    // Approach 1 ..........

    // vector<vector<int>> ways;

    // void printPaths(vector<int>& nums,vector<int>& output,vector<bool>& visited){
    //     if(output.size() == nums.size()){
    //         ways.push_back(output);
    //         return ;
    //     }
    //     for(int index = 0 ; index < nums.size() ; index++){
    //         if(visited[index] == true){ // if the current index is true then then that index will bw skipped
    //             continue;
    //         }
    //         output.push_back(nums[index]);
    //         visited[index] = true;

    //         printPaths(nums,output,visited); // here we are only rearranging the items so we want all the items that is why there is no no choice during recursion call

    //         output.pop_back();
    //         visited[index] = false;
    //     }
    // }
    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<bool>visited(nums.size()); // this will tell if the index is visited or not if visited then we will not visit it again
    //     vector<int>output;
    //     printPaths(nums,output,visited);
    //     return ways;
    // }


    // Approach 2..........

    vector<vector<int>> ways;

    void swap(vector<int>& nums, int i,int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    void printPaths(vector<int>& nums , int i){
        if(i == nums.size()){
            vector<int>output;
            for(int val: nums){
                output.push_back(val);
            }
            ways.push_back(output);
            return ;
        }
        for(int j = i; j < nums.size();j++){
            swap(nums,i,j);
            printPaths(nums,i+1);
            swap(nums,i,j);
        }
    }
    vector<vector<int>> permute(vector<int>& nums){
        printPaths(nums,0);
        return ways;
    }

};