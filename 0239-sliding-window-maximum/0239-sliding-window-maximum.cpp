class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>res(n-k+1);
        deque<int>q;
        int window = 0;
        for(int i=0; i<n; i++){
            if(q.size() > 0 && q.front() <= i - k){// if index goes out of window then pop
                q.pop_front();
            }
            while(q.size() > 0 && nums[q.back()] < nums[i]){
                q.pop_back();
            }
            q.push_back(i);

            if(i >= k - 1){
                res[window++] =  nums[q.front()];
            } 
        }
        return res;
    }
};