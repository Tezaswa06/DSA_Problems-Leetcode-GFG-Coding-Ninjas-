class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long> vis;

        for (int i = 0; i < nums.size(); i++) {
            if (i - indexDiff - 1 >= 0) {
                vis.erase((long)nums[i - indexDiff - 1]);
            }

            auto pos = vis.lower_bound((long)nums[i] - valueDiff);

            if (pos != vis.end() && abs(*pos - (long)nums[i]) <= valueDiff) {
                return true;
            }

            vis.insert((long)nums[i]);
        }
        return false;
    }
};