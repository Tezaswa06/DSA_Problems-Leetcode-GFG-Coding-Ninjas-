class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> missingandduplicate;

        for(int i=0;i<n;i++){
            int originalnumber = nums[i] % (n+1);
            nums[originalnumber-1] += (n+1);
        }
        int dup = 0;
        int miss = 0;
        for(int i=0;i<n;i++){
            int frequencycount = nums[i]/(n+1);
            if(frequencycount>1){
                dup += i+1;
            }
            if(frequencycount<1){
                miss+= i+1;
            }
        }
        missingandduplicate.push_back(dup);
        missingandduplicate.push_back(miss);
        return missingandduplicate;
    }
};