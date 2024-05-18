class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>stk;

        for(int idx = 0; idx < asteroids.size(); idx++){
            int right = asteroids[idx];
            if(right > 0){
                stk.push_back(right);
            }
            else if(stk.size() == 0 || stk[stk.size() - 1] < 0){
                stk.push_back(right);             
            }
            else if(stk[stk.size() - 1] < -right){
                stk.pop_back();
                idx--;
            }
            else if(stk[stk.size()-1] == -right){
                stk.pop_back();
            }
        }
        vector<int>res(stk.size());
        for(int i = 0; i < res.size(); i++){
            res[i] = stk[i];
        }
        return res;
    }
};