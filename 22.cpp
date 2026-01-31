#include <bits/stdc++.h>

class Solution {
public:
    void generate(int open, int close, string op, vector<string>& ans) {
        if (open == 0 && close == 0) {
            ans.push_back(op);
            return;
        }

        if (open > close) {
            return;
        }

        if (open == close) {
            op.push_back('(');
            generate(open - 1, close, op, ans);
            return;
        }

        if (open > 0) {
            string op1 = op;
            op1.push_back('(');
            generate(open - 1, close, op1, ans);
        }

        if (close > 0) {
            string op2 = op;
            op2.push_back(')');
            generate(open, close - 1, op2, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        int open = n;
        int close = n;
        string op = "";

        generate(open, close, op, ans);

        return ans;
    }
};