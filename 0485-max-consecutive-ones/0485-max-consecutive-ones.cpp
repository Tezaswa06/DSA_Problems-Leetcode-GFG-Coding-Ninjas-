class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                continue;
            }
            int countOnes = 0;
            while(i < nums.size() && nums[i] == 1){
                countOnes++;
                i++;
            }
            maxCount = max(maxCount,countOnes);
        }
        return maxCount;
    }
};