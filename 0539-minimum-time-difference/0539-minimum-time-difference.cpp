class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>minutes;
        for(int i = 0 ; i < timePoints.size(); i++){
            int hrs = stoi(timePoints[i].substr(0,2));
            int mins = stoi(timePoints[i].substr(3,2));
            minutes.push_back(hrs*60+mins);
        }
        sort(minutes.begin(),minutes.end());
        int ans = INT_MAX;
        for(int i = 0 ; i < minutes.size()-1;i++){
            
            int minTime = minutes[i+1] - minutes[i];
            ans = min(minTime , ans);
        }
        ans = min(ans,1440 - minutes[minutes.size()-1] + minutes[0]);
        return ans;
        
    }
};