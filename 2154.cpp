#include <bits/stdc++.h>

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> arr;
        for (int num : nums) {
            arr.insert(num);
        }
        while (arr.count(original)) {
            original *= 2;
        }
        return original;
    }
};