#include <bits/stdc++.h>

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        map<char, int> idx;
        for (int i = 0; i < s.size(); i++) {
            idx[s[i]] = i;
        }

        int ans = 0;
        for (int i = 0; i < t.size(); i++) {
            ans += abs(i - idx[t[i]]);
        }

        return ans;
    }
};