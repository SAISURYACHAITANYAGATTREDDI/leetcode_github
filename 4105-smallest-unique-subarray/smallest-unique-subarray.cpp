class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> sa(n), rank(n), tmp(n);
        iota(sa.begin(), sa.end(), 0);
        rank = nums;

        for (int k = 1; ; k <<= 1) {
            auto cmp = [&](int i, int j) {
                if (rank[i] != rank[j]) return rank[i] < rank[j];
                int ri = (i + k < n ? rank[i + k] : -1);
                int rj = (j + k < n ? rank[j + k] : -1);
                return ri < rj;
            };

            sort(sa.begin(), sa.end(), cmp);

            tmp[sa[0]] = 0;
            int classes = 1;

            for (int idx = 1; idx < n; ++idx) {
                int a = sa[idx - 1];
                int b = sa[idx];

                int a1 = rank[a], b1 = rank[b];
                int a2 = (a + k < n ? rank[a + k] : -1);
                int b2 = (b + k < n ? rank[b + k] : -1);

                if (a1 != b1 || a2 != b2) ++classes;
                tmp[b] = classes - 1;
            }

            rank.swap(tmp);

            if (classes == n) break;
            if (k > n) break;
        }

        vector<int> posRank(n);
        for (int i = 0; i < n; ++i) posRank[sa[i]] = i;

        vector<int> lcp(n, 0); 
        int h = 0;

        for (int i = 0; i < n; ++i) {
            int r = posRank[i];

            if (r == 0) {
                h = 0;
                continue;
            }

            int j = sa[r - 1];

            while (i + h < n && j + h < n && nums[i + h] == nums[j + h]) {
                ++h;
            }

            lcp[r] = h;
            if (h > 0) --h;
        }

        int ans = n;
        for (int r = 0; r < n; ++r) {
            int maxLCP = 0;

            if (r > 0) maxLCP = max(maxLCP, lcp[r]);
            if (r + 1 < n) maxLCP = max(maxLCP, lcp[r + 1]);

            int pos = sa[r];
            int len = maxLCP + 1;

            if (pos + len <= n) {
                ans = min(ans, len);
            }
        }
        return ans;
    }
};