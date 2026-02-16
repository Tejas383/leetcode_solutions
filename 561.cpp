#include <bits/stdc++.h>

class Solution {
public:
    int lcs(string str, int n, string rev, int m) {
        if (n == 0 || m == 0)
            return 0;
        
        if (str[n - 1] == rev[m - 1]) {
            return (1 + lcs(str, n - 1, rev, m - 1));
        }
        return max(lcs(str, n - 1, rev, m), lcs(str, n, rev, m - 1));
    }

    int longestPalindromeSubseq(string s) {
        string str = s;
        string rev = s;
        reverse(rev.begin(), rev.end());

        return lcs(str, str.size(), rev, rev.size());
    }
};