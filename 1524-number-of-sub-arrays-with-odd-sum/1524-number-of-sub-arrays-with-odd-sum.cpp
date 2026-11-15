class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int oddPrefixes = 0;
        int evenPrefixes = 1;
        int prefixParity = 0;

        long long answer = 0;

        for (int num : arr) {
            prefixParity ^= (num & 1);

            if (prefixParity == 1) {
                answer += evenPrefixes;
                oddPrefixes++;
            } 
            else {
                answer += oddPrefixes;
                evenPrefixes++;
            }
            answer %= MOD;
        }
        return static_cast<int>(answer);
    }
};