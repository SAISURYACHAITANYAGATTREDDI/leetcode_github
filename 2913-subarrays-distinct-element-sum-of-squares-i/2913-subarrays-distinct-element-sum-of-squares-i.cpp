class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> distinct;
            for (int j = i; j < n; j++) {
                distinct.insert(nums[j]);
                int cnt = distinct.size();
                ans += cnt * cnt;
            }
        }
        return ans;
    }
};