#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int a = 0;
        int b = 1;
        int c;
        int i = 0;
        while (i < n) {
            c = a + b;
            a = b;
            b = c;
            i++;
        }
        return c;
    }
};