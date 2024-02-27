
class Solution {
public:
    int floorinarray(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                right = mid - 1;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int floor = floorinarray(arr, x);
        int ceil = floor + 1;

        for (int count = 0; count < k; count++) {
            int floordist = (floor == -1) ? INT_MAX : (x - arr[floor]);
            int cieldist = (ceil == arr.size()) ? INT_MAX : (arr[ceil] - x);

            if (floordist <= cieldist) {
                floor--;
            } else {
                ceil++;
            }
        }

        vector<int> res;
        for (int idx = floor + 1; idx < ceil; idx++) {
            res.push_back(arr[idx]);
        }

        return res;
    }
};
