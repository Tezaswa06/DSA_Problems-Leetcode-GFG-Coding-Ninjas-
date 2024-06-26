class Solution {
public:
    int localInversioncount = 0;// adjacent inversion pairs
    long globalInversioncount = 0;// normal inversion pair 

    vector<int>Merge(vector<int>& arr1,vector<int>& arr2){
        int n1 = arr1.size();
        int n2 = arr2.size();
        vector<int>arr3(n1 + n2);

        int p1 = 0;
        int p2 = 0;
        int p3 = 0;

        while(p1 < n1 && p2 < n2){
            if(arr1[p1] <= arr2[p2]){
                arr3[p3] = arr1[p1];
                p3++;
                p1++;
            }
            else{
                globalInversioncount += (n1 - p1);
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
    vector<int>MergeSort(vector<int>& nums,int left,int right){
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

    bool isIdealPermutation(vector<int>& nums) {
        MergeSort(nums,0,nums.size()-1);

        for(int i = 0 ; i < nums.size()-1 ; i++){
            if(nums[i] > nums[i+1]){
                localInversioncount++;
            }
        }
        return localInversioncount == globalInversioncount;
    }
};