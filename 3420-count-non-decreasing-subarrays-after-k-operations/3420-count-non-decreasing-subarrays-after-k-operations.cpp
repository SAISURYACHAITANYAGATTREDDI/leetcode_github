class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + nums[i];
        }

        vector<int> nxt(n, n);
        vector<int> st;
        st.reserve(n);

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.back()] <= nums[i]) {
                st.pop_back();
            }
            if (!st.empty()) nxt[i] = st.back();
            st.push_back(i);
        }

        const int LOG = 20;

        vector<vector<int>> up(LOG, vector<int>(n + 1, n));
        vector<vector<long long>> jump(LOG, vector<long long>(n + 1, 0));

        for (int i = 0; i < n; ++i) {
            up[0][i] = nxt[i];
            jump[0][i] = 1LL * nums[i] * (nxt[i] - i);
        }

        for (int j = 1; j < LOG; ++j) {
            for (int i = 0; i <= n; ++i) {
                int mid = up[j - 1][i];
                up[j][i] = up[j - 1][mid];
                jump[j][i] = jump[j - 1][i] + jump[j - 1][mid];
            }
        }

        auto prefixMaxSum = [&](int l, int r) -> long long {
            long long sum = 0;
            int pos = l;

            for (int j = LOG - 1; j >= 0; --j) {
                if (up[j][pos] <= r) {
                    sum += jump[j][pos];
                    pos = up[j][pos];
                }
            }

            sum += 1LL * nums[pos] * (r - pos + 1);
            return sum;
        };

        auto cost = [&](int l, int r) -> long long {
            long long sumPrefixMax = prefixMaxSum(l, r);
            long long sumElements = pref[r + 1] - pref[l];
            return sumPrefixMax - sumElements;
        };

        long long answer = 0;

        for (int l = 0; l < n; ++l) {
            int low = l, high = n - 1;
            int maxR = l - 1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (cost(l, mid) <= k) {
                    maxR = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            if (maxR >= l) {
                answer += maxR - l + 1;
            }
        }
        return answer;
    }
};