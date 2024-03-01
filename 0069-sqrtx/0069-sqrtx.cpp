class Solution {
public:
    int mySqrt(int x) {

        // Approach 1
    //     long answer = 0;
    //     for(long index = 0;index<=x;index++){
    //         if(index*index<=x){
    //             answer = index;
    //         }
    //         else{
    //             break;
    //         }
    //     }
    //     return answer;

    // Approach 2 (Binary search)
        long left = 0;
        long right = x;

        while(left<=right){
            long mid = left + (right - left) / 2;
            if(mid * mid <= x){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return right;

    }
};