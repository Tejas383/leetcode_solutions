#include <bits/stdc++.h>

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);

        int l = 0;
        int r = nums.size() - 1;
        int idx = nums.size() - 1;

        while (l <= r) {
            int powL = nums[l] * nums[l];
            int powR = nums[r] * nums[r];

            if (powL > powR) {
                ans[idx] = powL;
                l++;
            } else {
                ans[idx] = powR;
                r--;
            }
            idx--;
        }

        return ans;
    }
};