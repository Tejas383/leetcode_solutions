#include <bits/stdc++.h>

class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                float root = sqrt(pow(i, 2) + pow(j, 2));
                if (floor(root) == root && root <= n) {
                    count++;
                }
            }
        }
        return count;
    }
};