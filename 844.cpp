#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stS;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#') {
                if (!stS.empty())
                    stS.pop();
                continue;
            }
            stS.push(s[i]);
        }

        stack<char> stT;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == '#') {
                if (!stT.empty())
                    stT.pop();
                continue;
            }
            stT.push(t[i]);
        }

        return (stS == stT);
    }
};