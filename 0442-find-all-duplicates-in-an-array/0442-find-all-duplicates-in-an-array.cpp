class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int originalnumber = nums[i]%(n+1);
            nums[originalnumber-1]+=(n+1);
        }
        vector<int>answer;
        for(int i=0;i<n;i++){
            int frequencycount = nums[i]/(n+1);
            if(frequencycount>1){
                answer.push_back(i+1);
            }
        }
        return answer;
    }
};