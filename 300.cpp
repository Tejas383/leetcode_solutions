#include <bits/stdc++.h>

class Solution {
public:
    int solve(vector<int>& nums, int i, int prevIdx, vector<vector<int>>& dp) {
        if (dp[i][prevIdx + 1] != -1)
            return dp[i][prevIdx + 1];

        if (i == nums.size())
            return dp[i][prevIdx + 1] = 0;
        
        int take = 0;
        if (prevIdx == -1 || nums[i] > nums[prevIdx])
            take = 1 + solve(nums, i + 1, i, dp);
        int skip = solve(nums, i + 1, prevIdx, dp);

        return dp[i][prevIdx + 1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int> (nums.size() + 1, -1));
        return solve(nums, 0, -1, dp);
    }
};