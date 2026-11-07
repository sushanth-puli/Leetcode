class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> window;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            auto it = window.lower_bound((long long)nums[i] - valueDiff);

            if (it != window.end() &&
                *it <= (long long)nums[i] + valueDiff) {
                return true;
            }

            window.insert(nums[i]);

            if (i >= indexDiff) {
                window.erase(nums[i - indexDiff]);
            }
        }

        return false;
    }
};