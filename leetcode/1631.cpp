class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};

        // pq = {dist, i, j}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});

        vector<vector<int>> dis(heights.size(), vector<int> (heights[0].size(), INT_MAX));
        dis[0][0] = 0;
        
        int ans = 0;

        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();

            auto d = t[0];
            auto i = t[1];
            auto j = t[2];

            if (i == heights.size() - 1 && j == heights[0].size() - 1)
                return d;

            for (int k = 0; k < 4; k++) {
                int ii = i + dx[k];
                int jj = j + dy[k];

                if (
                    ii >= 0 && jj >= 0
                    && ii < heights.size() && jj < heights[0].size()
                ) {
                    if (abs(heights[ii][jj] - heights[i][j]) < dis[ii][jj]) {
                        int effort = max(d, abs(heights[ii][jj] - heights[i][j]));

                        if (effort < dis[ii][jj]) {
                            dis[ii][jj] = effort;
                            pq.push({effort, ii, jj});
                        }
                    }
                }
            }
        }

        return ans;
    }
};