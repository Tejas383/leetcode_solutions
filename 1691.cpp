class Solution {
public:
    int solve(vector<vector<int>>& cuboids, int curr, int prev, vector<vector<int>>& dp) {
        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        if (curr == cuboids.size())
            return dp[curr][prev + 1] = 0;
        
        int take = 0;
        if (prev == -1 || 
         (cuboids[curr][0] >= cuboids[prev][0]
          && cuboids[curr][1] >= cuboids[prev][1]
          && cuboids[curr][2] >= cuboids[prev][2])
         )
            take = cuboids[curr][2] + solve(cuboids, curr + 1, curr, dp);
        int notTake = solve(cuboids, curr + 1, prev, dp);

        return dp[curr][prev + 1] = max(take, notTake);
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto& cuboid : cuboids)
            sort(cuboid.begin(), cuboid.end());
        
        sort(cuboids.begin(), cuboids.end());

        vector<vector<int>> dp(cuboids.size() + 1, vector<int> (cuboids.size() + 1, -1));

        return solve(cuboids, 0, -1, dp);
    }
};