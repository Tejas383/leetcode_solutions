#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        vector<vector<string>> ans;

        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            m[temp].push_back(strs[i]);
        }
        for (auto el : m) {
            ans.push_back(el.second);
        }

        return ans;
    }
};