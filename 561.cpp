#include <bits/stdc++.h>

class Solution {
public:
    int lcs(string str, int n, string rev, int m, vector<vector<int>>& dp) {
        if (dp[n][m] != -1)
            return dp[n][m];

        if (n == 0 || m == 0)
            return dp[n][m] = 0;
        
        if (str[n - 1] == rev[m - 1]) {
            return dp[n][m] = (1 + lcs(str, n - 1, rev, m - 1, dp));
        }
        return dp[n][m] = max(lcs(str, n - 1, rev, m, dp), lcs(str, n, rev, m - 1, dp));
    }

    int longestPalindromeSubseq(string s) {
        string str = s;
        string rev = s;
        reverse(rev.begin(), rev.end());

        vector<vector<int>> dp(str.size() + 1, vector<int> (rev.size() + 1, -1));

        return lcs(str, str.size(), rev, rev.size(), dp);
    }
};