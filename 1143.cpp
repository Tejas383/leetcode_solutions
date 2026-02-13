#include <bits/stdc++.h>

class Solution {
public:
    int lcs(string& str1, int n, string& str2, int m, vector<vector<int>>& dp) {
        if (dp[n][m] != -1)
            return dp[n][m];

        if (n == 0 || m == 0)
            return 0;
        
        if (str1[n - 1] == str2[m - 1])
            return dp[n][m] = (1 + lcs(str1, n - 1, str2, m - 1, dp));
        
        return dp[n][m] = max(lcs(str1, n - 1, str2, m, dp), lcs(str1, n, str2, m - 1, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int> (text2.size() + 1, -1));

        return lcs(text1, text1.size(), text2, text2.size(), dp);
    }
};