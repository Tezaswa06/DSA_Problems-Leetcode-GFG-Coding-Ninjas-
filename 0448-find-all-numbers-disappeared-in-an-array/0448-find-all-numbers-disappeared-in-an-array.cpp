class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>missingNo;
        int n = nums.size();

        for(int i=0; i < n; i++){
            int val = nums[i] % (n + 1);
            nums[val - 1] += (n + 1);
        }

        for(int i = 0; i < n; i++){
            if(nums[i] < n + 1){
                missingNo.push_back(i+1);
            }
        }

        return missingNo;
    }
};
