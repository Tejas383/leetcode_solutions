#include <bits/stdc++.h>

class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1)
            return 0;
        
        if (k % 2 == 1) {
            return kthGrammar(n - 1, (k + 1) / 2);
        } else {
            return !kthGrammar(n - 1, (k + 1) / 2);
        }
    }
};

// this row's kth element will depend on the previous row's ((k + 1) / 2)th element