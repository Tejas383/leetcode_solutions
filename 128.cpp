#include <bits/stdc++.h>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for (int num : nums) 
            s.insert(num);
        
        int maxLen = 0;
        int len = 0;
        int prev = INT_MIN;
        bool flag = false;
        for (auto el : s) {
            if (el == prev + 1) {
                len++;
                maxLen = max(maxLen, len);
            } else {
                len = 0;
                flag = true;
            }
            prev = el;
        }

        if (flag)
            maxLen++;
        
        return maxLen;
    }
};