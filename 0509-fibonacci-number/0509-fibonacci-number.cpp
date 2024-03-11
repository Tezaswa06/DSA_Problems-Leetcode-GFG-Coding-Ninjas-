class Solution {
public:
    int fib(int n) {
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }

        int prev1 = fib(n - 1);
        int prev2 = fib(n - 2);
        int curr = prev1 + prev2;

        return curr;
    }
};