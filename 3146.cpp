#include <bits/stdc++.h>

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        char arr[26];
        for (int i = 0; i < s.size(); i++) {
            arr[s[i] - 'a'] = i;
        }

        int ans = 0;
        for (int i = 0; i < t.size(); i++) {
            ans += abs(i - arr[t[i] - 'a']);
        }

        return ans;
    }
};