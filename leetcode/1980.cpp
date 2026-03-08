#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// Approach Name: Binary Conversion + Missing Number Search
// Convert to decimal -	Each binary string is converted into its decimal equivalent using bin()
// Store values -	All decimal numbers are stored in a vector bins
// Search missing number - Iterate through all possible numbers from 2ⁿ − 1 down to 0 and check which number is not present in bins
// Convert back	- The missing decimal number is converted back to a binary string of length n using dec()

// Time complexity = O(2^n * n)
// Space complexity = O(n)


class Solution {
public:
    int bin(string str) {
        int b = 0;

        for (auto s : str) {
            int n = (s == '0') ? 0 : 1;
            b = b * 2 + n;
        }

        return b;
    }

    string dec(int num, int len) {
        string d = "";

        while (num > 0) {
            d += num % 2 + '0';
            num /= 2;
        }

        while (d.size() < len)
            d += '0';

        reverse(d.begin(), d.end());
        return d;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();

        vector<int> bins;
        for (auto num : nums) {
            bins.push_back(bin(num));
        }

        int num = 0;
        for (int i = (1 << n) - 1; i >= 0; i--) {
            if (find(bins.begin(), bins.end(), i) == bins.end()) {
                num = i;
                break;
            }
        }

        return dec(num, n);
    }
};