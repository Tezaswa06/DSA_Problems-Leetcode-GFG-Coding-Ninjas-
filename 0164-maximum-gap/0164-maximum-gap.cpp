class Solution {
public:
    vector<int>CountSort(vector<int>& nums,int place){
        vector<int>freqarr(10);

        for(int element : nums){
            int digit = (element % (10 * place))/place;
            freqarr[digit]++;
        }

        for(int index = 1 ; index < freqarr.size() ; index++){
            freqarr[index] += freqarr[index - 1];
        }

        vector<int>result(nums.size());
        for(int i = nums.size()-1 ; i >= 0 ; i--){
            int element = nums[i];
            int digit = (element % (place * 10)) / place;
            freqarr[digit]--;
            int last = freqarr[digit];
            result[last] = element;
        }
        return result;
    }
    int maximumGap(vector<int>& nums) {
        // radix sort
        for(int place = 1 ; place <= pow(10,8) ; place *= 10){
            nums = CountSort(nums,place);
        }
        for(int i = 0; i < nums.size() ; i++){
            cout<<nums[i]<<" ";
        }
        int maxgap = 0;
        for(int i = 1; i < nums.size() ; i++){
            if(nums[i] - nums[i - 1] > maxgap){
                maxgap = nums[i] - nums[i - 1];
            }
        }
        return maxgap;
    }
};