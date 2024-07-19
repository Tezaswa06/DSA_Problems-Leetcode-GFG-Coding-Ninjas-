class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1){
            return 1;
        }
        // below ptrs are pointing to indexes not the value
        int ptr2 = 0;
        int ptr3 = 0;
        int ptr5 = 0;

        vector<int>ugly;
        ugly.push_back(1);

        for(int i=1; i<n; i++){
            int a = ugly[ptr2] * 2;
            int b = ugly[ptr3] * 3;
            int c = ugly[ptr5] * 5;

            int min1 = min(a,min(b,c));
            ugly.push_back(min1);

            if(a == min1){
                ptr2++;
            }
            if(b == min1){
                ptr3++;
            }
            if(c == min1){
                ptr5++;
            }
        }
        return ugly[n-1];
    }
};