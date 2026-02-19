class Solution {
public:
    int solve(vector<int>& nums, int n) {
        if (n == 0)
            return 0;

        if (n == 1)
            return nums[0];
        
        int take = nums[n - 1] + solve(nums, n - 2);

        int notTake = solve(nums, n - 1);

        return max(take, notTake);
    } 

    int rob(vector<int>& nums) {
        return solve(nums, nums.size());
    }
};