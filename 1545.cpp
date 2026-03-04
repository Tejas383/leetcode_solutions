#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    char solve(int n, int k) {
        if (n == 1)
            return '0';
        
        if (k == (1 << (n - 1)))
            return '1';
        if (k < (1 << (n - 1)))
            return solve(n - 1, k);
        
        char bit = solve(n - 1, (1 << n) - k);

        if (bit == '1')
            return '0';
        return '1';
    }

    char findKthBit(int n, int k) {
        return solve(n, k);
    }
};