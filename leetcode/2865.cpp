#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        long long total = INT_MIN;
        for (int idx = 0; idx < heights.size(); idx++) {
            vector<int> temp = heights;
            for (int i = idx - 1; i >= 0; i--) {
                temp[i] = min(temp[i], temp[i + 1]);
            }
            for (int i = idx + 1; i < temp.size(); i++) {
                temp[i] = min(temp[i], temp[i - 1]);
            }
            
            long long ans = 0;
            for (int i = 0; i < temp.size(); i++) {
                ans += temp[i];
            }

            total = max(total, ans);
        } 
        return total;
    }
};