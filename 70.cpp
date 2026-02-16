#include <bits/stdc++.h>

class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if (dp[n] != -1)
            return dp[n];
        
        if (n == 0 || n == 1)
            return dp[n] = 1;
        
        // take one step
        int one = solve(n - 1, dp);

        // take two steps
        int two = solve(n - 2, dp);

        return dp[n] = one + two;
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);

        return solve(n, dp);
    }
};