class Solution {
public:
    bool isPowerOfFour(int n) {
        int setBits = 0;
        for(int bit=0; bit<32; bit++){
            if((n & (1 << bit)) != 0){
                setBits++;
                if((bit & 1) == 1){// if set bit is at odd index then ans is not correct
                    return false;
                }
            }
        }
        return (setBits == 1);
    }
};