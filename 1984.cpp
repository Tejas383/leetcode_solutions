#include <bits/stdc++.h>

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX;

        sort(nums.begin(), nums.end());

        int i = 0;
        int j = k - 1;

        while (j < nums.size()) {
            int diff = nums[j++] - nums[i++];
            ans = min(ans, diff);
        }

        return ans;
    }
};