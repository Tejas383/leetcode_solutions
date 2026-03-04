class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (auto pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) 
                q.push(i);
        }

        vector<int> vec;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            vec.push_back(node);
            for (auto n : adj[node]) {
                if (inDegree[n] > 0) {
                    inDegree[n]--;
                    if (inDegree[n] == 0)
                        q.push(n);
                }
            }
        }

        for (auto i : inDegree)
            if (i != 0)
                return vector<int> ();

        return vec;
    }
};