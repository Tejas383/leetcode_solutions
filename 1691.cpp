class Solution {
public:
    int solve(vector<vector<int>>& cuboids, int curr, int prev) {
        if (curr == cuboids.size())
            return 0;
        
        int take = 0;
        if (prev == -1 || 
         (cuboids[curr][0] >= cuboids[prev][0]
          && cuboids[curr][1] >= cuboids[prev][1]
          && cuboids[curr][2] >= cuboids[prev][2])
         )
            take = cuboids[curr][2] + solve(cuboids, curr + 1, curr);
        int notTake = solve(cuboids, curr + 1, prev);

        return max(take, notTake);
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto& cuboid : cuboids)
            sort(cuboid.begin(), cuboid.end());
        
        sort(cuboids.begin(), cuboids.end());

        return solve(cuboids, 0, -1);
    }
};