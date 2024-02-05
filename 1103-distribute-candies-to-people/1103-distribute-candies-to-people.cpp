class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people,0);
        int currcandy = 1;
        int ind = 0;
        while(currcandy<=candies){
            ans[ind]  = ans [ind] + currcandy;
           candies =  candies - currcandy;
            currcandy++;
            ind++;
            ind = ind%num_people;

        }

        ans[ind] = ans[ind] + candies;
        return ans;
    }
};