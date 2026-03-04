#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                string op = tokens[i];
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                if (op == "+") {
                    st.push(a + b);
                } else if (op == "-") {
                    st.push(a - b);
                } else if (op == "*") {
                    st.push(a * b);
                } else {
                    st.push(a / b);
                }

                continue;
            }
            st.push(stoi(tokens[i]));
        }

        return st.top();
    }
};