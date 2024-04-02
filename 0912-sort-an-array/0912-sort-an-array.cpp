class Solution {
public:

// Approach 1 merge sort with return
    // vector<int>Merge(vector<int>& arr1,vector<int>& arr2){
    //     int n1 = arr1.size();
    //     int n2 = arr2.size();
    //     vector<int>arr3(n1+n2);
    //     int p1 = 0;
    //     int p2 = 0;
    //     int p3 = 0;
    //     while(p1 < n1 && p2 < n2){
    //         if(arr1[p1] <= arr2[p2]){
    //             arr3[p3] = arr1[p1];
    //             p1++;
    //             p3++;
    //         }
    //         else{
    //             arr3[p3] = arr2[p2];
    //             p2++;
    //             p3++;
    //         }
    //     }
    //     while(p1 < n1){
    //         arr3[p3] = arr1[p1];
    //         p3++;
    //         p1++;
    //     }
    //     while(p2 < n2){
    //         arr3[p3] = arr2[p2];
    //         p3++;
    //         p2++;
    //     }

    //     return arr3;
    // }
    // vector<int>MergeSort(vector<int>& nums,int left,int right){

    //     if(left == right){
    //         vector<int>result;
    //         result.push_back(nums[left]);
    //         return result;

    //     }


    //     int mid = left + (right -left)/2;
    //     vector<int>larr = MergeSort(nums,left,mid);
    //     vector<int>rarr = MergeSort(nums,mid+1,right);
    //     return Merge(larr,rarr);

    // }
    // vector<int> sortArray(vector<int>& nums) {
    //     return MergeSort(nums,0,nums.size()-1);
    // }

    // Approach 2 // without return

    // void Merge(vector<int>& nums,int l1,int r1,int l2,int r2){
        
    //     vector<int>arr3(r2-l1+1);
    //     int p1 = l1;
    //     int p2 = l2;
    //     int p3 = 0;
    //     while(p1 <= r1 && p2 <= r2){
    //         if(nums[p1] <= nums[p2]){
    //             arr3[p3] = nums[p1];
    //             p1++;
    //             p3++;
    //         }
    //         else{
    //             arr3[p3] = nums[p2];
    //             p2++;
    //             p3++;
    //         }
    //     }
    //     while(p1 <= r1){
    //         arr3[p3] = nums[p1];
    //         p3++;
    //         p1++;
    //     }
    //     while(p2 <= r2){
    //         arr3[p3] = nums[p2];
    //         p3++;
    //         p2++;
    //     }

    //     for(int index = l1 ; index <= r2 ; index++){
    //         nums[index] = arr3[index - l1];
    //     }
    // }
    // void MergeSort(vector<int>& nums,int left,int right){
    //     if(left >= right){
    //         return ;
    //     }
    //     int mid = left + (right - left)/2;
    //     MergeSort(nums,left,mid);
    //     MergeSort(nums,mid+1,right);
    //     Merge(nums,left,mid,mid+1,right);
    // }
    // vector<int> sortArray(vector<int>& nums){
    //     MergeSort(nums,0,nums.size()-1);
    //     return nums;
    // }


    // Approach 3 Quick sort

    // void swap(vector<int>& nums,int left,int right){
    //     int temp = nums[left];
    //     nums[left] = nums[right];
    //     nums[right] = temp;
    // }
    // int partitioning(vector<int>& nums,int left,int right){
    //     int pivot = nums[right];
    //     int i = left;
    //     int j = left;
    //     while(j <= right){
    //         if(nums[j] <= pivot){
    //             swap(nums,i,j);
    //             i++;
    //             j++;
    //         }
    //         else{
    //             j++;
    //         }
    //     }
    //     return (i-1);
    // }
    // void randomize(vector<int>& nums,int left,int right){
    //     double d = static_cast<double>(rand()) / (static_cast<double>(RAND_MAX) + 1.0);
    //     int index = d * (right - left + 1) + left;
    //     swap(nums , index , right);
    // }
    // void QuickSort(vector<int>& nums,int left,int right){
    //     if(left >= right){
    //         return ;
    //     }
    //     randomize(nums,left , right);
    //     int mid = partitioning(nums,left,right);
    //     QuickSort(nums,left,mid-1);
    //     QuickSort(nums,mid+1,right);
    // }
    // vector<int> sortArray(vector<int>& nums){
    //     QuickSort(nums,0,nums.size()-1);
    //     return nums;
    // }

    // Approach 4 counting sort 

    vector<int> sortArray(vector<int>& nums){
        int min = -50000;
        int max = 50000;
        vector<int>frequencyarr(max - min + 1);

        // this array is to store the frequencies of the element in the nums array
        for(int element : nums){
            frequencyarr[element - min]++;
        }
        for(int idx = 1 ; idx < frequencyarr.size();idx++){
            frequencyarr[idx] += frequencyarr[idx-1]; 
        }
        vector<int>result(nums.size());
        for(int i=nums.size()-1;i >= 0;i--){
            int ele = nums[i];
            frequencyarr[ele-min]--;
            int last = frequencyarr[ele-min];
            result[last] = ele;
        }
        return result;
    }
};