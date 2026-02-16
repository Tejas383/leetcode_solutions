#include <bits/stdc++.h>

class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while (i <= j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(string s, int i, int j) {
        if (i >= j)
            return 0;
            
        if (isPalindrome(s, i, j))
            return 0;

        int ans = INT_MAX;
        for (int k = i; k < j; k++) {
            int left = solve(s, i, k);
            int right = solve(s, k + 1, j);
            int temp = left + right + 1;
            ans = min(ans, temp);
        }
        return ans;
    }

    int minCut(string s) {
        return solve(s, 0, s.size() - 1);
    }
};