#include <bits/stdc++.h>

class Solution {
public:
    int solve(vector<int>& nums, int i, int prevIdx) {
        if (i == nums.size())
            return 0;
        
        int take = 0;
        if (prevIdx == -1 || nums[i] > nums[prevIdx])
            take = 1 + solve(nums, i + 1, i);
        int skip = solve(nums, i + 1, prevIdx);

        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        return solve(nums, 0, -1);
    }
};