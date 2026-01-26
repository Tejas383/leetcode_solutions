#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int min_diff = INT_MAX;
        for (int i = 1; i < arr.size(); i++) {
            min_diff = min(min_diff, arr[i] - arr[i - 1]); 
        }

        vector<vector<int>> ans;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] == min_diff) {
                vector<int> p;
                p.push_back(arr[i - 1]);
                p.push_back(arr[i]);
                ans.push_back(p);
            }
        }

        return ans;
    }
};