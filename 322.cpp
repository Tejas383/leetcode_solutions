#include <bits/stdc++.h>

class Solution {
public:
    int helper(vector<int>& coins, int amount, int n, vector<vector<int>>& dp) {
        if (dp[n][amount] != -1)
            return dp[n][amount];

        if (n == 0)
            return dp[n][amount] = 1e9;
        
        if (amount == 0)
            return dp[n][amount] = 0;
        
        if (coins[n - 1] <= amount)
            return dp[n][amount] = min(1 + helper(coins, amount - coins[n - 1], n, dp), helper(coins, amount, n - 1, dp));
        
        return dp[n][amount] = helper(coins, amount, n - 1, dp);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1, vector<int> (amount + 1, -1));
        int ans = helper(coins, amount, coins.size(), dp);
        return ans >= 1e9 ? -1 : ans;
    }
};