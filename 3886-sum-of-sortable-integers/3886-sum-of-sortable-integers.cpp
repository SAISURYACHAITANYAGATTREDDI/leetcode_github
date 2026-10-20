class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int ans = 0;

        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;

            bool ok = true;
            for (int l = 0; l < n && ok; l += k) {
                if (!isRotation(nums, sortedNums, l, k)) {
                    ok = false;
                }
            }

            if (ok) ans += k;
        }
        return ans;
    }

private:
    bool isRotation(const vector<int>& a, const vector<int>& b, int l, int k) {
        vector<int> pi(k, 0);

        for (int i = 1; i < k; ++i) {
            int j = pi[i - 1];

            while (j > 0 && a[l + i] != a[l + j]) {
                j = pi[j - 1];
            }

            if (a[l + i] == a[l + j]) {
                ++j;
            }

            pi[i] = j;
        }

        int j = 0;

        for (int pos = 0; pos < 2 * k; ++pos) {
            int val = b[l + (pos % k)];

            while (j > 0 && val != a[l + j]) {
                j = pi[j - 1];
            }

            if (val == a[l + j]) {
                ++j;
            }

            if (j == k) {
                int start = pos - k + 1;

                if (start < k) {
                    return true;
                }

                j = pi[j - 1];
            }
        }
        return false;
    }
};