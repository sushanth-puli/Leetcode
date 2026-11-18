using ll = long long;
#include <vector>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag, 
             tree_order_statistics_node_update> pbds;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        pbds ost;

        for(int i = 0; i < n; i++) {
            ost.insert({nums[i], i});
        } 

        int ans = 0;

        for(int i = 0; i < n; i++) {
            ll val = nums[i];
            ost.erase({val, i});

            int find = floor(((double)val - 1.0) / 2.0);
            int count = ost.order_of_key({find + 1, -1});
            ans += count;
        }
        return ans;
    }
};