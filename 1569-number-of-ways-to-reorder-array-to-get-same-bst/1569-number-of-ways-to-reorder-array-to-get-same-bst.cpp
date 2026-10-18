class Solution {
private:
    static const int MOD = 1000000007;
    long long dfs(const vector<int>& arr, const vector<vector<long long>>& C) {
        if (arr.size() <= 1) return 1;

        int root = arr[0];
        vector<int> left, right;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < root) left.push_back(arr[i]);
            else right.push_back(arr[i]);
        }

        long long ways = C[arr.size() - 1][left.size()];
        ways = ways * dfs(left,  C) % MOD;
        ways = ways * dfs(right, C) % MOD;
        return ways;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> C(n + 1, vector<long long>(n + 1, 0));
        
        for (int i = 0; i <= n; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }
        return (int)((dfs(nums, C) - 1 + MOD) % MOD);
    }
};