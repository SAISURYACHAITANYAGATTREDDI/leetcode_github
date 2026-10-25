class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int closedIslands = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    bool touchesBoundary = false;
                    stack<pair<int, int>> st;
                    st.push({i, j});
                    visited[i][j] = true;

                    while (!st.empty()) {
                        auto [r, c] = st.top();
                        st.pop();

                        if (r == 0 || r == m - 1 || c == 0 || c == n - 1) {
                            touchesBoundary = true;
                        }

                        for (auto& dir : dirs) {
                            int nr = r + dir[0];
                            int nc = c + dir[1];

                            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                                grid[nr][nc] == 0 && !visited[nr][nc]) {
                                visited[nr][nc] = true;
                                st.push({nr, nc});
                            }
                        }
                    }

                    if (!touchesBoundary) {
                        ++closedIslands;
                    }
                }
            }
        }
        return closedIslands;
    }
};