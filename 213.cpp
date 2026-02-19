class Solution {
public:
    int solve(vector<int>& nums, int n, int i) {
        if (n == i)
            return 0;
        
        if (n == i + 1)
            return nums[i];
        
        return max(nums[n - 1] + solve(nums, n - 2, i), solve(nums, n - 1, i));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        return max(solve(nums, n, 1), solve(nums, n - 1, 0));
    }
};