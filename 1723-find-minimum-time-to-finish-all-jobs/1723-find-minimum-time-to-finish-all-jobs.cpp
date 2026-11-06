class Solution {
public:
    int n, inf = 1e9;
    vector<int> masks;
    vector<vector<int>> dp;

    int f(int mask, int k) {
        if((1 << n) - 1 == mask)
            return 0;

        if(k == 0)
            return inf;

        int& ret = dp[mask][k];

        if(~ret)
            return ret;

        ret = inf;
        int rem = ((1 << n) - 1) ^ mask;

        for(int sub = rem; sub; sub = (sub - 1) & rem) 
            ret = min(ret, max(masks[sub], f(mask | sub, k - 1)));

        return ret;
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        n = jobs.size();

        masks.resize(1 << n);
        dp.resize(1 << n, vector<int>(k + 1, -1));

        for(int mask = 0; mask < 1 << n; ++mask) 
            for(int i = 0; i < n; ++i) 
                if(mask & (1 << i)) 
                    masks[mask] += jobs[i];
        
        return f(0, k);
    }
};