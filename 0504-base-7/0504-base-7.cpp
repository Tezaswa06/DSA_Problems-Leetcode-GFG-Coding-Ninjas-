class Solution {
public:
    string convertToBase7(int num) {
        long res = 0;
        long power = 1;// intially when we find first remainder of n then we multiply it with 10 to the power 0 that is why we have taken 1
        int b = 7;

        while(num != 0){
            int remainder = (num % b);
            res = res + power * remainder;
            num = num / 7;
            power = power * 10;
        }
        return to_string(res);
    }
};