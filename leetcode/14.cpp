#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];

        int len = strs.size();
        int i = 1;
        while (i < len) {
            int j = 0;
            string res = "";
            while (j < strs[i].length() && j < ans.length()) {
                if (ans[j] == strs[i][j]) {
                    res += ans[j];
                } else {
                    break;
                }
                j++;
            }
            ans = res;

            i++;
        } 

        return ans;
    }
};