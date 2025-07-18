#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        stack<char> st;

        while (i < s.size()) {
            string str = "";
            if (s[i] == ']') {
                string conc = "";
                while (st.top() != '[') {
                    conc += st.top();
                    st.pop();
                }
                st.pop();

                string numStr = "";
                while (!st.empty() && isdigit(st.top())) {
                    numStr += st.top();
                    st.pop();
                }
                reverse(numStr.begin(), numStr.end());
                int num = stoi(numStr);
                for(int j = 0; j < num; j++) {
                    str += conc;
                }
                for (int j = str.size() - 1; j >= 0; j--) {
                    st.push(str[j]);
                }
                
                i++;
            } else {
                st.push(s[i]);
                i++;
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};