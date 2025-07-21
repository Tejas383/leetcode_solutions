#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int i = 0, j = 0;
        int cnt = 0;
        while (j < s.size()) {
            if (s[i] == s[j]) {
                cnt++;
                if (cnt < 3)
                    ans += s[j];
                j++;
            } else {
                cnt = 0;
                i = j;
            }
        }
        return ans;
    }
};