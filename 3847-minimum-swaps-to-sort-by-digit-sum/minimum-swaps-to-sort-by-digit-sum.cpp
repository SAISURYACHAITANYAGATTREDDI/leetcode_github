class Solution {
public:
    static int digitSum(int x) {
        int s = 0;
        while (x > 0) {
            s += x % 10;
            x /= 10;
        }
        return s;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end(), [](int a, int b) {
            int sa = digitSum(a), sb = digitSum(b);
            if (sa != sb) return sa < sb;
            return a < b;
        });

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) pos[nums[i]] = i;
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == sorted[i]) continue;

            int j = pos[sorted[i]]; 
            swap(nums[i], nums[j]);

            pos[nums[i]] = i; 
            pos[nums[j]] = j; 

            swaps++;
        }
        return swaps;
    }
};