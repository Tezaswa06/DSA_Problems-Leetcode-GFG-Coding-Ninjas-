class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int n = gain.size();
        vector<int>prefixsum(n,0);
        prefixsum[0] = gain[0];
        for(int i=1;i<n;i++){
            prefixsum[i] = gain[i]+prefixsum[i-1];
        }
        
        int maxaltitude = 0;
        for(int i=0;i<prefixsum.size();i++){
            if(prefixsum[i]>maxaltitude){
                maxaltitude = prefixsum[i];
            }
        }
        return maxaltitude;
    }
};