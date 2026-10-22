#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dist(2, vector<int>(n, -1));
        queue<pair<int, int>> q;

        dist[0][0] = 0;
        q.push({0, 0});

        while (!q.empty()) {
            auto [rev, s] = q.front();
            q.pop();

            int nd = dist[rev][s] + 1;
            int nr = rev;
            int ns = (s + 1) % n;
            if (dist[nr][ns] == -1) {
                dist[nr][ns] = nd;
                q.push({nr, ns});
            }

            nr = 1 - rev;
            ns = (n - s) % n;
            if (dist[nr][ns] == -1) {
                dist[nr][ns] = nd;
                q.push({nr, ns});
            }
        }

        auto norm = [&](int x) {
            x %= n;
            if (x < 0) x += n;
            return x;
        };

        int ans = INT_MAX;
        int s = norm(-nums[0]);
        bool ok = true;

        for (int k = 0; k < n; ++k) {
            if (nums[k] != norm(k - s)) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans = min(ans, dist[0][s]);
        }

        s = norm(n - 1 - nums[0]);
        ok = true;

        for (int k = 0; k < n; ++k) {
            if (nums[k] != norm(n - 1 - k - s)) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans = min(ans, dist[1][s]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};