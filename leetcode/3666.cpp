#include <string>
#include <vector>
#include <climits>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        int m = 0;

        vector<int> dist(n + 1, INT_MAX);
        // idx -> num of zeros
        // dist[idx] -> how many steps taken to reach idx num of zeros
        vector<set<int>> nodeSets(2);
        // nodeSets[0] -> even indices
        // nodeSets[1] -> odd indices
        // to store all the unvisited nodes

        for (int i = 0; i <= n; i++) {
            nodeSets[i % 2].insert(i);
            // fill the nodeSets
            if (i < n && s[i] == '0')
                m++;
                // count the num of zeros initially in the string
        }

        queue<int> q;
        q.push(m);
        dist[m] = 0;
        // num of steps taken to reach m zeros is 0,
        // where m is the num of 0s initially
        nodeSets[m % 2].erase(m);
        // since we have visited that node

        while (!q.empty()) {
            m = q.front();
            q.pop();

            // z lies in the range : z1 ≤ z ≤ z2
            int z1 = max(k - n + m, 0);
            // number of ones in s = n - m (size - num(0s))
            // => chars to flip - 0s flipped ≤ num of 1s
            // => k - z ≤ n - m
            // solving the inequality, we get,
            // z ≥ k - n + m
            // and
            // the minimum number of 0s we can select is 0
            int z2 = min(m, k);
            // the maximum number of 0s we can select is:
            //  either - the num of 0s currently in the string
            //  or - the number of flips allowed
            // therefore, the minimum of 2

            // number of 0s if z = z1
            int r = m + k - 2 * z1;
            // number of 0s if z = z2
            int l = m + k - 2 * z2;

            // we choose the set from numSets, whose parity is same as l
            auto& nodeSet = nodeSets[l % 2];

            // iterate over nodeSet
            // iterate over all the nodes in the range [l, r]
            for (
                auto it = nodeSet.lower_bound(l); // returns the 1st value >= l
                it != nodeSet.end() // continue till the end of nodeSet
                && *it <= r; // and until it < r
            ) {
                int m2 = *it;
                dist[m2] = dist[m] + 1;
                q.push(m2);

                it = next(it);
                nodeSet.erase(m2);
            }
        }

        if (dist[0] == INT_MAX)
            return -1;
        return dist[0];
    }
};