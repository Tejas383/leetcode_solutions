#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int cnt = 1;
        for (int i = 0; i < s.size(); i++) {
            if (i > 0 && s[i] == s[i - 1]) 
                cnt++;
            else 
                cnt = 1;
            
            if (cnt < 3)
                ans += s[i];
        }
        return ans;
    }
};