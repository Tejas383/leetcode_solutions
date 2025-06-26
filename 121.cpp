#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;

        int i = 0;
        int min = 0;
        int ans = 0;

        while (i < prices.size()) {
            if (prices[i] < prices[min]) {
                min = i;
            }
            ans = max(ans, prices[i] - prices[min]);
            i++;
        }

        return ans;
    }
};