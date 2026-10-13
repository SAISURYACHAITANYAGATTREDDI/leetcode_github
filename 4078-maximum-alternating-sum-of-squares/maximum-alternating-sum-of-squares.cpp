class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = abs(nums[i]);
        }

        sort(a.begin(), a.end());

        long long ans = 0;
        int negCount = n / 2;

        for (int i = 0; i < n; i++) {
            long long sq = a[i] * a[i];
            if (i < negCount) {
                ans -= sq;
            } else {
                ans += sq;
            }
        }
        return ans;
    }
};