class Solution {
public:
    int findsqrt(int x){
        long left = 0;
        long right = x;
        while(left <= right){
            long mid = left + (right - left)/2;
            if(mid * mid <= x){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }  
        return right;
    }
    bool isPerfectSquare(int num) {
        int sqrt = findsqrt(num);
        return sqrt * sqrt == num;
    }
};