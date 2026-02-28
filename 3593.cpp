#include <vector>
using namespace std;

class Solution {
public:
    long long dfs(int node, int parent, vector<vector<int>>&adj, vector<int>& cost, int& count) {
        // maximum sum of child node
        long long maxSum = 0;
        // number of children the node has
        int children = 0;
        // number of children which have maximum sum
        int maxSumChildren = 0;

        for (auto child : adj[node]) {
            if (child == parent)
                continue;

            children++;

            // calculate sum for each child node
            long long sum = dfs(child, node, adj, cost, count);

            if (sum > maxSum) {
                maxSum = sum; // update maxSum 
                maxSumChildren = 1; // number of children with that sum is 1
            } else if (sum == maxSum) 
                maxSumChildren += 1; // number of children with that sum increments
        }

        // if the number of children in more than the number of children with maximum sum
        if (children > maxSumChildren)
            count += (children - maxSumChildren);
            // increment the count with the number of child nodes whose value will have to be changed

        // cost from that node to leaf node will be cost of the node + maxSum
        long long sum = cost[node] + maxSum;
        // this is the maximum cost for that path

        return sum;
    }

    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        int count = 0;
        int r = dfs(0, -1, adj, cost, count);

        return count;
    }
};