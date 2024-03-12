class Solution {
public:

// Approach 1 which is not optimised and will give stack over flow error

    // double pow(double x,int n){
    //     if(n == 0){
    //         return 1.0;
    //     }

    //     double smallans = pow(x , n-1);
    //     double bigans = smallans * x;
    //     return bigans;
    // }

    // approach 2

    double pow(double x,long n){
        if(n == 0){
            return 1.0;
        }
        if(n % 2 == 1){
            double smallans = pow(x , n - 1);
            double bigans = smallans * x;
            return bigans;
        }
        double smallans = pow(x , n/2);
        double bigans = smallans * smallans;
        return bigans;
    }

    double myPow(double x, int n) {
        if(n < 0){
            return 1.0 / pow(x , -1l * n);
        }
        return pow(x,n);
    }
};