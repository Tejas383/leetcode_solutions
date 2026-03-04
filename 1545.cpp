#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        bool flip = false;

        while (n > 1) {
            if (k == (1 << (n - 1))) {
                if (flip)
                    return '0';
                return '1';
            }

            if (k > (1 << (n - 1))) {
                k = (1 << n) - k;
                flip = !flip;
            }

            n--;
        }

        if (flip)
            return '1';
        return '0';
    }
};