class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int min = -100;
        int max = 100;
        vector<int>freqarr(max - min + 1);// created freq array which will calculate the freq of ele
        // pass 1 creating and storing the frequencies of the elemetnts
        for(int elem : nums){
            freqarr[elem - min]++;
        }

        // pass2 create bucket array in which buckets will be there 
        // no of buckets = size of input array + 1 means in input array same freq element will be there till the size of array

        vector<vector<int>>buckets(nums.size()+1);
        
        // storing the elements in the bucket according to there frequencies means if 10 and 20 are having 1 freq then they will be stored in 1 freq bucket
        for(int elem = min ; elem <= max ; elem++){
            int count = freqarr[elem - min]; // this will extract the count of elements which is already stored in freqarr
            if(count == 0){
                continue;
            }
            buckets[count].push_back(elem);
        }

        // pass 3 creating sorted array
        int index = 0;
        for(int bucket = 1 ; bucket < buckets.size() ; bucket++){
            reverse(buckets[bucket].begin(),buckets[bucket].end());
            for(int elem : buckets[bucket]){
                for(int freq = 0 ; freq < bucket ; freq++){
                    nums[index] = elem;
                    index++;
                }
            }
        }
        return nums;
    }
};