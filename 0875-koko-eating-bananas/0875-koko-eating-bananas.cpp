class Solution {
public:
    // first approach as we are using linear search so it will give time limit exceed
    bool ispossible(vector<int>& piles,int availableHours,int speed){
        long sum = 0;// this will calculate all the time taken to eat the bananas
        for(long bananas : piles){
            sum += bananas/speed;
            if(bananas % speed != 0){
                sum++;
            }
        }
        return (sum <= availableHours);
    }
    int minEatingSpeed(vector<int>& piles, int hours) {
        // long maxSpeed = pow(10,9);

        // for(int speed=1;speed<maxSpeed;speed++){
        //     if(ispossible(piles,hours,speed)==true){
        //         return speed;
        //     }
        // }
        // return -1;
        long left = 1;
        long right = pow(10,9);
        while(left <= right){
            long mid = left + (right - left)/2;
            if(ispossible(piles,hours,mid)==true){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};