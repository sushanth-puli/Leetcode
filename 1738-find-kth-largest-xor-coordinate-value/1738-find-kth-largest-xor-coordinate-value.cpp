class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> prefix(n, vector<int>(m, 0));
        vector<int> values;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                prefix[i][j] = matrix[i][j];

                if (i > 0) prefix[i][j] ^= prefix[i - 1][j];
                if (j > 0) prefix[i][j] ^= prefix[i][j - 1];
                if (i > 0 && j > 0) prefix[i][j] ^= prefix[i - 1][j - 1];

                values.push_back(prefix[i][j]);
            }
        }

        sort(values.rbegin(), values.rend());

        return values[k - 1];
    }
};