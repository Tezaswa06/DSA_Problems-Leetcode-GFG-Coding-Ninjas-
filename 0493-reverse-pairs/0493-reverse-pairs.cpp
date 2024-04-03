class Solution {
public:

    int count = 0;
    void countPairs(vector<int>& arr1,vector<int>& arr2){
        int n1 = arr1.size();
        int n2 = arr2.size();
        int p1 = 0;
        int p2 = 0;
        while(p1 < n1 && p2 < n2){
            if(arr1[p1] <= 2l*arr2[p2]){
                p1++;
            }
            else{
                count += (n1 -p1);
                p2++;
            }
        }
    }
    vector<int>Merge(vector<int>& arr1,vector<int>& arr2){
        int n1 = arr1.size();
        int n2 = arr2.size();
        vector<int>arr3(n1+n2);
        
        int p1 = 0 , p2 = 0 , p3 = 0;
        countPairs(arr1,arr2);
        while(p1 < n1 && p2 < n2){
            if(arr1[p1] <= arr2[p2]){
                arr3[p3] = arr1[p1];
                p3++;
                p1++;
            }
            else{
                arr3[p3] = arr2[p2];
                p3++;
                p2++;
            }
        }
        while(p1 < n1){
            arr3[p3] = arr1[p1];
            p3++;
            p1++;
        }
        while(p2 < n2){
            arr3[p3] = arr2[p2];
            p3++;
            p2++;
        }
        return arr3;
    }
    vector<int>MergeSort(vector<int>& nums, int left,int right){
        if(left == right){
            vector<int>result;
            result.push_back(nums[left]);
            return result;
        }
        int mid = left + (right - left)/2;
        vector<int>arr1 = MergeSort(nums,left,mid);
        vector<int>arr2 = MergeSort(nums,mid+1,right);
        return Merge(arr1,arr2);
    }
    int reversePairs(vector<int>& nums) {
        MergeSort(nums,0,nums.size()-1);
        return count;
    }
};