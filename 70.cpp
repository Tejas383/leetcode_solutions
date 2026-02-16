#include <bits/stdc++.h>

class Solution {
public:
    int solve(int n) {
        if (n == 0)
            return 1;
        
        if (n == 1)
            return 1;
        
        // take one step
        int one = solve(n - 1);

        // take two steps
        int two = solve(n - 2);

        return one + two;
    }

    int climbStairs(int n) {
        return solve(n);
    }
};