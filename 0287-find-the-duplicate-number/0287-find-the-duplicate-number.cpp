class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int originalnumber = nums[i]%(n+1);
            nums[originalnumber] += (n+1);
        }

        for(int i=0;i<n;i++){
            int frequencycount = nums[i]/(n+1);
            if(frequencycount>1){
                return i;
            }
        }
        return 0;
    }
};