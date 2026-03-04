#include <bits/stdc++.h>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1, vector<int> (amount + 1));

        // we can not make a particular amount if number of coins is 0
        // therefore, the number of coins is set to max
        // MAX_INT - 1 -> to control integer overflow
        for (int j = 0; j < dp[0].size(); j++)
            dp[0][j] = INT_MAX - 1;
        
        // to create the amount of 0, we donot need any coins
        // therefore, the whole column is 0
        for (int i = 0; i < dp.size(); i++) 
            dp[i][0] = 0;
        
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[i].size(); j++) {
                if (coins[i - 1] <= j)
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
                else 
                    dp[i][j] = dp[i - 1][j];
            }
        }

        if (dp[coins.size()][amount] >= INT_MAX - 1) 
            return -1;

        return dp[coins.size()][amount];
    }
};