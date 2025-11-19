#include <bits/stdc++.h>

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int first = -1;
        int second = -1;
        int index = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > first) {
                second = first;
                first = nums[i];
                index = i;
            } else if (nums[i] > second) {
                second = nums[i];
            } else {
                continue;
            }
        }

        if (first >= 2 * second)
            return index;
        else 
            return -1;
    }
};