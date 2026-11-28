#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        long long B = budget;

        long long minPrice = LLONG_MAX;
        for (auto &it : items) {
            minPrice = min(minPrice, (long long)it[1]);
        }

        vector<int> freq(n + 1, 0);
        for (auto &it : items) {
            freq[it[0]]++;
        }

        vector<int> multiples(n + 1, 0);
        for (int f = 1; f <= n; f++) {
            for (int m = f; m <= n; m += f) {
                multiples[f] += freq[m];
            }
        }

        long long twoQ = 2LL * minPrice;

        unordered_map<long long, long long> bonusCount;
        for (auto &it : items) {
            int f = it[0];
            long long price = it[1];

            long long cnt = (long long)multiples[f] - 1;

            if (cnt > 0 && price < twoQ) {
                bonusCount[price] += cnt;
            }
        }

        vector<pair<long long, long long>> groups(bonusCount.begin(), bonusCount.end());
        sort(groups.begin(), groups.end());

        long long bonuses = 0;

        for (auto &[price, cnt] : groups) {
            if (B < price) break;

            long long take = min(cnt, B / price);
            bonuses += take;
            B -= take * price;
        }

        long long answer = 2LL * bonuses + B / minPrice;

        return (int)answer;
    }
};