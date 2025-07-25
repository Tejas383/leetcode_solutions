#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (!st.empty() && st.top() == s[i]) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        string str = "";
        while (!st.empty()) {
            str += st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());

        return str;
    }
};