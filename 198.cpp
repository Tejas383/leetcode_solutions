class Solution {
public:
    int solve(vector<int>& nums, int n, vector<int>& dp) {
        if (dp[n] != -1) 
            return dp[n];
        
        if (n == 0)
            return dp[n] = 0;

        if (n == 1)
            return dp[n] = nums[0];
        
        int take = nums[n - 1] + solve(nums, n - 2, dp);
        int notTake = solve(nums, n - 1, dp);

        return dp[n] = max(take, notTake);
    } 

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);

        return solve(nums, nums.size(), dp);
    }
};