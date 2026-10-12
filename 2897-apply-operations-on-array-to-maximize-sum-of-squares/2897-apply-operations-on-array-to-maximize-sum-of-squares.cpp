class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        vector<long long> vals(k, 0);
        
        for (int b = 0; b < 31; ++b) {
            int cnt = 0;
            for (int x : nums) {
                if (x & (1 << b)) cnt++;
            }
            int take = min(cnt, k);
            long long bitVal = 1LL << b;
            for (int i = 0; i < take; ++i) {
                vals[i] += bitVal;
            }
        }

        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            long long v = vals[i] % MOD;
            ans = (ans + v * v) % MOD;
        }
        return (int)ans;
    }
};