class Solution {
public:
    int highestOneBit(int n) {
        n |= (n >> 1);
        n |= (n >> 2);
        n |= (n >> 4);
        n |= (n >> 8);
        n |= (n >> 16);
        return n - (n >> 1);
    }
    int rangeBitwiseAnd(int left, int right) {
        int lsb = highestOneBit(left ^ right);

        int res = left;
        while (lsb != 0) {
            res = res & ~lsb;
            lsb = lsb >> 1;
        }
        return res;
    }
};