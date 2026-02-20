class Solution {
public:
    // DFS function to check whether node 'i' is safe or not
    // Returns true  -> if the node is eventually safe
    // Returns false -> if the node is part of a cycle or leads to a cycle
    bool solve(vector<vector<int>>& adj, int i,
               vector<bool>& vis,          // marks if node has been visited
               vector<bool>& path,         // marks if node is in current DFS path
               set<int>& safeNodes,        // stores all safe nodes (sorted automatically)
               vector<bool>& cycle) {      // memoization: true means safe, false means unsafe

        vis[i] = true;     // mark current node as visited
        path[i] = true;    // mark current node in current recursion path

        bool b = true;     // assume current node is safe initially

        // Traverse all adjacent nodes
        for (auto node : adj[i]) {

            // If neighbour is not visited, recursively check it
            if (!vis[node])
                b = b && solve(adj, node, vis, path, safeNodes, cycle);

            // If neighbour is in current DFS path → cycle detected
            else if (path[node])
                b = false;

            // If neighbour already processed, use its stored result
            else 
                b = b && cycle[node];
        }

        path[i] = false;   // remove current node from recursion path

        // If 'b' is still true, this node is safe
        if (b)
            safeNodes.insert(i);

        cycle[i] = b;      // store result for memoization

        return b;          // return whether this node is safe
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();   // total number of vertices

        set<int> safeNodes;   // to store safe nodes in sorted order
        vector<bool> vis(V, false);    // visited array
        vector<bool> path(V, false);   // recursion stack tracker
        vector<bool> cycle(V, false);  // stores whether node is safe or not

        // Run DFS for every unvisited node
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                path[i] = true;                 // mark starting node in path
                bool b = solve(adj, i, vis, path, safeNodes, cycle);
            }
        }

        // Convert set to vector for final answer
        vector<int> ans;
        for (auto i : safeNodes)
            ans.push_back(i);
        
        return ans;
    }
};