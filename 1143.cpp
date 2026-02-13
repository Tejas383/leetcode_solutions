#include <bits/stdc++.h>

class Solution {
public:
    int lcs(string str1, int n, string str2, int m) {
        if (n == 0 || m == 0)
            return 0;
        
        if (str1[n - 1] == str2[m - 1])
            return (1 + lcs(str1, n - 1, str2, m - 1));
        
        return max(lcs(str1, n - 1, str2, m), lcs(str1, n, str2, m - 1));
    }

    int longestCommonSubsequence(string text1, string text2) {
        return lcs(text1, text1.size(), text2, text2.size());
    }
};