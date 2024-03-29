class Solution {
public:

    // Approach 1 counting zeroes ones and t

    // void sortColors(vector<int>& nums) {
    //    int zeroes = 0;
    //    int ones = 0;
    //    int twos = 0;
    //    for(int val : nums){
    //         if(val == 0){
    //             zeroes++;
    //         }
    //         else if(val == 1){
    //             ones++;
    //         }
    //         else{
    //             twos++;
    //         }
    //     }
    //     for(int i = 0 ; i < nums.size() ; i++){
    //         if(i < zeroes){
    //             nums[i] = 0;
    //         }
    //         else if(i < zeroes + ones){
    //             nums[i] = 1;
    //         }
    //         else{
    //             nums[i] = 2;
    //         }
    //     }
    // }

    // Approach 2 
    void swap(vector<int>& nums,int left,int right){
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
    }
    void sortColors(vector<int>& nums){
        int i = 0;
        int j = 0;
        int k = nums.size() - 1;
        while(j <= k){ // j jab tak k se bda na ho jaye tab tak kaam karna hai
            if(nums[j] == 0){
                swap(nums,i,j);
                i++;
                j++;
            }
            else if(nums[j] == 1){
                j++;
            }
            else{
                swap(nums,j,k);// hum jab yha pe j aur k ko swap kar rahe hai to hume ye nhi pta k se j ke paas humare paas kya aa rha hai isi liye j ko humne increment nhi kiya
                k--;
            }
        }
    }
};