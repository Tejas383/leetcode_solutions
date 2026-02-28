#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

// Approach 1: Explicit binary construction (TLE due to repeated string copying)

class Solution {
public:
    int concatenatedBinary(int n) {
        vector<string> concat(n + 1, "0");
        for (int i = 1; i <= n; i++) {
            string bin = "";

            int m = i;
            while (m > 0) {
                if (m % 2 == 0)
                    bin += '0';
                else
                    bin += '1';
                m /= 2;
            }
            reverse(bin.begin(), bin.end());

            concat[i] = concat[i - 1] + bin;
        }

        string bin = concat[n];
        int dec = 0;
        int mod = pow(10, 9) + 7;
        for (auto c : bin)
            dec = (dec * 2 + (c - '0')) % mod;

        return dec;
    }
};