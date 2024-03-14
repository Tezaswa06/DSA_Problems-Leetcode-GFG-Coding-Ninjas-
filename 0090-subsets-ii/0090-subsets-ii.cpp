class Solution {
public:
    void printsubsequences(vector<int>& input,int index,vector<int>& output,vector<vector<int>>& result){
        if(index == input.size()){
            result.push_back(output);
            return ;
        }
        output.push_back(input[index]);
        printsubsequences(input,index+1,output,result);
        output.pop_back();

        if(output.size() > 0 && output[output.size()-1] == input[index]){
            return;
        }
        printsubsequences(input,index+1,output,result);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         vector<vector<int>> result;
         vector<int>output;
         printsubsequences(nums,0,output,result);
         return result;
    }
};