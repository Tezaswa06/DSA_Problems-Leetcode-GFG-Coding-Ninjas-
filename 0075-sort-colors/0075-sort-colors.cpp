class Solution {
public:
    void sortColors(vector<int>& nums) {
       int zeroes = 0;
       int ones = 0;
       int twos = 0;
       for(int val : nums){
            if(val == 0){
                zeroes++;
            }
            else if(val == 1){
                ones++;
            }
            else{
                twos++;
            }
        }
        for(int i = 0 ; i < nums.size() ; i++){
            if(i < zeroes){
                nums[i] = 0;
            }
            else if(i < zeroes + ones){
                nums[i] = 1;
            }
            else{
                nums[i] = 2;
            }
        }
    }
};