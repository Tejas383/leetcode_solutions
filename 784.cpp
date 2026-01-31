#include <bits/stdc++.h>

class Solution {
public:
    void permute(string ip, string op, vector<string>& ans) {
        if (ip == "") {
            ans.push_back(op);
            return;
        }
        
        if (isdigit(ip[0])) {
            op.push_back(ip[0]);
            ip.erase(ip.begin() + 0);
            permute(ip, op, ans);
            return;
        }

        string op1 = op;
        string op2 = op;

        op1.push_back((char)tolower(ip[0]));
        op2.push_back((char)toupper(ip[0]));

        ip.erase(ip.begin() + 0);

        permute(ip, op1, ans);
        permute(ip, op2, ans);

    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;

        string ip = s;
        string op = "";

        permute(ip, op, ans);

        return ans;
    }
};