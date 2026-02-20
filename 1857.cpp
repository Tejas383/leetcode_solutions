#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        // Adjacency list
        vector<vector<int>> adj(colors.size());
        
        // Store indegree of each node
        // indegree of ith node = indegree[i]
        vector<int> indegree(colors.size(), 0);

        // Build adjacency list and compute indegrees
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);  // directed edge u -> v
            indegree[edge[1]]++;              // increment indegree of v, since the edge is coming to v
        }
        
        // Queue for Kahn’s Algorithm (Topological Sort)
        queue<int> q;
        
        // Push all nodes with indegree 0 (starting points)
        for (int i = 0; i < colors.size(); i++) {
            if (indegree[i] == 0) 
                q.push(i);
        }

        // vec[n][j] = maximum count of color 'j' along any path ending at node n
        vector<vector<int>> vec(colors.size(), vector<int>(26, 0));
        
        int ans = 0;  // Store the maximum color frequency across all paths

        // Perform Topological Sort (BFS)
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // Increment the count of the current node's color in 'vec'
            vec[node][colors[node] - 'a']++;
            
            // Update global maximum answer
            ans = max(ans, vec[node][colors[node] - 'a']);

            // Traverse all neighbors
            for (int i = 0; i < adj[node].size(); i++) {
                int n = adj[node][i];

                // Update neighbor's color frequencies
                // Take max for each color from current node
                for (int j = 0; j < 26; j++) {
                    vec[n][j] = max(vec[n][j], vec[node][j]);
                }

                // Reduce indegree after processing edge
                indegree[n]--;

                // If indegree becomes 0, push to queue
                if (indegree[n] == 0) {
                    q.push(n);
                }
            }
        }

        // If any node still has indegree > 0, graph has a cycle
        for (auto node : indegree)
            if (node != 0)
                return -1;  // Cycle detected, therefore, return -1
        
        return ans;  // if no cycle, Return maximum color value
    }
};