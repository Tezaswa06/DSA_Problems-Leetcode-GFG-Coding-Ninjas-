class Solution {
public:
    vector<int>prefix(vector<int>& height){
        vector<int>pref(height.size());
        pref[0] = height[0];
        for(int i=1; i<height.size(); i++){
            pref[i] = max(pref[i-1],height[i]);
        }
        return pref;
    }
    vector<int>suffix(vector<int>& height){
        vector<int>suff(height.size());
        int n = height.size();
        suff[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            suff[i] = max(suff[i+1],height[i]);
        }
        return suff;
    }
    int trap(vector<int>& height) {
        vector<int>prefixMax = prefix(height);
        vector<int>suffixMax = suffix(height);
        int totalWater = 0;
        for(int i=0; i<height.size(); i++){
            int leftMax = prefixMax[i];
            int rightMax = suffixMax[i];
            if((height[i] < leftMax) && (height[i] < rightMax)){
                totalWater += min(leftMax,rightMax) - height[i];
            }
        }
        return totalWater;
    }
};