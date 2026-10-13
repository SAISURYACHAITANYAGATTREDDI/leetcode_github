class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            res[i] = abs(nums[i]);
        }

        sort(res.begin(), res.end());

        int l = 0;
        int r = n - 1;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                nums[i] = res[r--];
            } else {
                nums[i] = res[l++];
            }
        }

        long long score = 0;
        for (int i = 0; i < n; i++) {
            long long sq = 1LL * nums[i] * nums[i];
            if (i % 2 == 0) {
                score += sq;
            } else {
                score -= sq;
            }
        }

        return score;
    }
};