class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1'000'000'007;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> nextR(m, vector<int>(n, -1));
        vector<vector<int>> nextD(m, vector<int>(n, -1));

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 0) {
                    nextR[i][j] = nextD[i][j] = i * n + j;
                } else {
                    if (i + 1 < m) nextR[i][j] = nextD[i + 1][j];
                    if (j + 1 < n) nextD[i][j] = nextR[i][j + 1];
                }
            }
        }

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        auto add = [&](int r, int c, int val) {
            if (r < 0 || r >= m || c < 0 || c >= n) return;
            dp[r][c] += val;
            if (dp[r][c] >= MOD) dp[r][c] -= MOD;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) continue;
                int cur = dp[i][j];
                if (cur == 0) continue;

                if (j + 1 < n) {
                    int code = nextR[i][j + 1];
                    if (code != -1) add(code / n, code % n, cur);
                }

                if (i + 1 < m) {
                    int code = nextD[i + 1][j];
                    if (code != -1) add(code / n, code % n, cur);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};