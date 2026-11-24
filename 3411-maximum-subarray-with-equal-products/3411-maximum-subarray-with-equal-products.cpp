class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        const int LIMIT = 25200;

        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            int g = 0;
            int l = 1;

            for (int j = i; j < n; ++j) {
                prod *= nums[j];
                if (prod > LIMIT) break;
                g = std::gcd(g, nums[j]);
                l = std::lcm(l, nums[j]);

                if (prod == 1LL * g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};