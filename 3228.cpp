#include <bits/stdc++.h>

class Solution {
public:
    int maxOperations(string s) {
        int counter = 0;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                while (i < s.length() - 1 && s[i + 1] == '0') {
                    i++;
                }
                ans += counter;
            } else {
                counter++;
            }
        }
        return ans;
    }
};