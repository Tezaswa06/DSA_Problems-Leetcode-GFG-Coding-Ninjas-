class Solution {
public:
    bool ispossible(vector<int>& position,int allowedBalls,int maxDist){
        int currBall = 1;
        int prevPosition = position[0];

        for(int currPosition : position){
            if(currPosition - prevPosition >= maxDist){
                currBall++;
                prevPosition = currPosition;
            }
        }
        return (currBall >= allowedBalls);
    }

    int maxDistance(vector<int>& position, int balls) {
        sort(position.begin(),position.end());
        int n = position.size();

        int left = 0;
        int right = position[n-1] - position[0];// this we have added to maximise the distance between two balls 

        while(left <= right){
            int mid = left + (right - left)/2;

            if(ispossible(position,balls,mid)==true){
                left = mid + 1; // to maximise the distance we are going towards right
            }
            else{
                right = mid - 1;
            }
        }
        return right;

    }
};