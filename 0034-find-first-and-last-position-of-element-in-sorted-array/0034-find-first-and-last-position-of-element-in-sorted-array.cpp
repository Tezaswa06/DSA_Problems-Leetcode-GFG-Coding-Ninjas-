class Solution {
public:
    int firstOccurenceOfNo(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size()-1;

        while(left<=right){
            int mid = left + (right-left)/2;

            if(nums[mid]==target){
                right = mid -1;
            }
            else if(nums[mid]<target){
                left = mid+1;
            }
            else{
                right = mid -1;
            }
        }
        return left;
    }
    int lastOccurenceOfNo(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size()-1;

        while(left<=right){
            int mid = left + (right-left)/2;

            if(nums[mid]==target){
                left = mid + 1;
            }
            else if(nums[mid]<target){
                left = mid+1;
            }
            else{
                right = mid -1;
            }
        }
        return right;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>answer;
        int firstoccr = firstOccurenceOfNo(nums,target);
        int lastoccr = lastOccurenceOfNo(nums,target);
        answer.push_back(firstoccr);
        answer.push_back(lastoccr);
        if (firstoccr > lastoccr){
            return {-1, -1};
        }

        return answer;
    }
};