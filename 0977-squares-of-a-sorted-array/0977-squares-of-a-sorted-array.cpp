class Solution {
public:
    // void swap(vector<int>& ans,int l,int r){
    //     int temp = ans[l];
    //     ans[l] = ans[r];
    //     ans[r] = temp;
    // }
    // int compare(vector<int>& ans,int l,int r){
    //     if(ans[l] < ans[r]){
    //         return -1;
    //     }
    //     else if(ans[l] > ans[r]){
    //         return +1;
    //     }
    //     else{
    //         return 0;
    //     }
    // }

    // Approach 1

    // vector<int> sortedSquares(vector<int>& nums) {
    //     vector<int>ans;
    //     for(int i = 0; i< nums.size() ; i++){
    //         nums[i] = nums[i] * nums[i];
    //         ans.push_back(nums[i]);
    //     }
    
    //     for(int i = 0 ; i < ans.size() - 1; i++){
    //         int countSwaps = 0;
    //         for(int j = 0 ; j < ans.size() - i - 1 ; j++){
    //             if(compare(ans,j,j+1) > 0){
    //                 swap(ans,j,j+1);
    //                 countSwaps++;
    //             }
    //         }
    //         if(countSwaps == 0){
    //             break;
    //         }
    //     }
    //     return ans;
    // }

    // Approach 2

    vector<int> sortedSquares(vector<int>& nums){
        vector<int>result(nums.size());
        int left = 0;
        int right = nums.size()-1;

        for(int index = nums.size()-1;index >= 0;index--){
            if(nums[left] * nums[left] > nums[right] * nums[right]){
                result[index] = nums[left] * nums[left];
                left++;
            }
            else{
                result[index] = nums[right] * nums[right];
                right--;
            }
        }
        return result;
    }
};