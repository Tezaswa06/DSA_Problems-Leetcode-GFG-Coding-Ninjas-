class Solution {
public:
    int floorinarray(vector<int>& heaters,int house){
        int left = 0;
        int right = heaters.size()-1;

        while(left<=right){
            int mid = left + (right - left) / 2;
            if(heaters[mid]==house){
                right = mid - 1;
            }
            else if(heaters[mid]<house){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return right;
    }
    int findclosestdistance(vector<int>& heaters,int house){
        int floor = floorinarray(heaters,house);
        int ceil = floor + 1;

        int floordist = (floor == -1) ? INT_MAX : (house - heaters[floor]);
        int ceildist = (ceil == heaters.size()) ? INT_MAX : (heaters[ceil] - house);

        return min(floordist,ceildist);
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());

        int minradius = 0;
        for(int house : houses){
            int radius = findclosestdistance(heaters,house);
            minradius = max(minradius,radius);
        }
        return minradius;
    }
};