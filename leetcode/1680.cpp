#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

// Approach 1: Explicit binary construction (MLE due to repeated string copying)
// Approach 2: Single growing binary string (still heavy due to string operations) - TLE
// Accepted: Bitwise shifting + power-of-two detection (O(n), O(1))

class Solution {
public:
    int concatenatedBinary(int n) {
        int mod = pow(10, 9) + 7;

        int bits = 0;
        long long ans = 0;

        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0)
                bits++;
            ans = ((ans << bits) | i) % mod;
        }

        return ans;
    }
};