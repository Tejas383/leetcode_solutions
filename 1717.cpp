#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calcScore(string s, int val, string& str) {
        int score = 0;
        stack<char> st;
        for (char ch : s) {
            if (st.empty())
                st.push(ch);
            else {
                if (ch == 'a' && st.top() == 'b') {
                    st.pop();
                    score += val;
                } else 
                    st.push(ch);
            }
        }

        while (!st.empty()) {
            str += st.top();
            st.pop();
        }
        return score;
    }
    int maximumGain(string s, int x, int y) {
        int score = 0;

        if (x > y) {
            swap(x, y);
            reverse(s.begin(), s.end());
        }

        string str = "";
        score += calcScore(s, y, str);
        s = str;
        str = "";
        score += calcScore(s, x, str);
        s = str;

        return score;
    }
};