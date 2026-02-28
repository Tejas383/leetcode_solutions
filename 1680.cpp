#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

// Approach 1: Explicit binary construction (MLE due to repeated string copying)
// Approach 2: Single growing binary string (still heavy due to string operations) - TLE

class Solution {
public:
    int concatenatedBinary(int n) {
        string prev = "0";
        string curr = "0";
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

            prev = curr;
            curr += bin;
        }

        string bin = curr;
        int dec = 0;
        int mod = pow(10, 9) + 7;
        for (auto c : bin)
            dec = (dec * 2 + (c - '0')) % mod;

        return dec;
    }
};