class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        string target = s;
        sort(target.begin(), target.end());

        int first = -1, last = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] != target[i]) {
                if (first == -1) first = i;
                last = i;
            }
        }

        if (first == -1) return 0;
        if (n == 2) return -1;
        if (!(first == 0 && last == n - 1)) return 1;

        int maxSuffix = 0;
        for (int i = 1; i < n; i++) {
            maxSuffix = max(maxSuffix, s[i] - 'a');
        }

        int minPrefix = 25;
        for (int i = 0; i < n - 1; i++) {
            minPrefix = min(minPrefix, s[i] - 'a');
        }

        if (s[0] - 'a' > maxSuffix && s[n - 1] - 'a' < minPrefix) return 3;
        return 2;
    }
};