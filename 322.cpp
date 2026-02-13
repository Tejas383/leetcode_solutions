#include <bits/stdc++.h>

class Solution {
public:
    int helper(vector<int>& coins, int amount, int n) {
        if (n == 0)
            return 1e9;
        
        if (amount == 0)
            return 0;
        
        if (coins[n - 1] <= amount)
            return min(1 + helper(coins, amount - coins[n - 1], n), helper(coins, amount, n - 1));
        
        return helper(coins, amount, n - 1);
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = helper(coins, amount, coins.size());
        return ans >= 1e9 ? -1 : ans;
    }
};