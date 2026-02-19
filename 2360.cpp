class Solution {
public:
    int solve(vector<int>& edges, int node, vector<bool>& vis, vector<int>& dist, int depth) {
        if (node == -1)
            return -1;

        int len = -1;

        if (!vis[node]) {
            vis[node] = true;
            dist[node] = depth;
            len = max(len, solve(edges, edges[node], vis, dist, depth + 1));
        } else {
            if (dist[node] != -1)
                len = abs(dist[node] - depth);
        }

        dist[node] = -1;

        return len;
    }

    int longestCycle(vector<int>& edges) {
        vector<bool> vis(edges.size(), false);
        vector<int> dist(edges.size(), -1);

        int ans = -1;

        for (int i = 0; i < edges.size(); i++) {
            if (!vis[i]) {
                dist[i] = 0;
                ans = max(ans, solve(edges, i, vis, dist, 0));
            }
        }

        return ans;
    }
};