class Solution {
public:
    vector<int> leftNSE(vector<int>& arr){
        int n = arr.size();
        stack<int>stk;
        vector<int>res(n);

        for(int idx = 0; idx < n; idx++){
            while(stk.size() > 0 && arr[stk.top()] >= arr[idx]){
                stk.pop();
            }
            res[idx] = (stk.size() > 0) ? stk.top() : -1;
            stk.push(idx);
        }
        return res;
    }
    vector<int> rightNSE(vector<int>& arr){
        int n = arr.size();
        stack<int>stk;
        vector<int>res(n);

        for(int idx = n - 1; idx >= 0; idx--){
            while(stk.size() > 0 && arr[stk.top()] >= arr[idx]){
                stk.pop();
            }
            res[idx] = (stk.size() > 0) ? stk.top() : n;
            stk.push(idx);
        }
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>left = leftNSE(heights);
        vector<int>right = rightNSE(heights);
        int maxi = 0;
        for(int idx = 0; idx < heights.size(); idx++){
            int area = heights[idx] * (right[idx] - left[idx] - 1);
            maxi = max(maxi,area);
        }
        return maxi;
    }
};