// explanation
// in the question it is clearly mentiones that alice will win 
// if(n+m) is odd then alice will win as he is the first one to pick the flower and the range of n and m is given[1,n] and [1,m] so these conditions must hold to determine the no of pairs
//if n is odd and m is even then we have to find ceil(n/2) * floor(m/2) or
// if m is odd and n is even then we have to find floor(n/2) * ciel(n/2) and add both the above step and return it in ans
class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans = 0;
        ans += 1ll * ((n+1)/2) * (m/2);
        ans += 1ll * (n/2) * ((m+1)/2);
        return ans;
    }
};