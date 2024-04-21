class Solution {
public:
    int minimumOperations(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        vector<int>cols(n + 1, -1);
        vector<vector<int>>dp(n + 1, vector<int>(10, 0x3f3f3f3f));
        vector<vector<int>>cnt(n, vector<int>(10, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m ; ++j) {
                cnt[i][A[j][i]]++;
            }
        }
        for (int i = 0; i < 10; ++i) {
            dp[n][i] = 0;
        }
        // for every column,
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < 10 ; ++j) {
                for (int k = 0; k < 10; ++k) {
                    if (j == k ) continue;
                    dp[i][j] = min(dp[i][j], m - cnt[i][j] + dp[i + 1][k]);
                }
            }
        }
        int res = 0x3f3f3f3f;
        res = *min_element(dp[0].begin(), dp[0].end());
        return res;
    }
};
