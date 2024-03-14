class Solution {
public:
    void printsubsets(vector<int>& input,int index, vector<int>& output,vector<vector<int>>& result){
        if(index == input.size()){
            result.push_back(output);
            return ;
        }
        output.push_back(input[index]);
        printsubsets(input , index + 1 , output , result);
        output.pop_back();

        printsubsets(input,index+1,output,result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>output;
        printsubsets(nums,0,output,result);
        return result;
    }
};