// Approach Name: Sliding Window on Doubled String (Rotation Trick)
// Time complexity = O(n)
// Space complexity = O(n)

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int i = 0;

        // a -> number of mismatches if pattern starts with '0' : 010101...
        // b -> number of mismatches if pattern starts with '1' : 101010...
        int a = 0, b = 0;

        // Count mismatches for the original string
        while (i < s.size()) {
            if (i % 2 == 0) {           // even index
                if (s[i] == '0')        // expected '0' for pattern 0101...
                    a++;
                else                    // expected '1' for pattern 1010...
                    b++;
            } else {                    // odd index
                if (s[i] == '1')        // expected '1' for pattern 0101...
                    a++;
                else                    // expected '0' for pattern 1010...
                    b++;
            }
            i++;
        }

        // minimum flips for current configuration
        int ans = min(a, b);

        // if length is even, rotations do not change parity pattern
        // so original calculation already gives the answer
        if (s.size() % 2 == 0)
            return ans;

        // if length is odd, rotation changes parity alignment
        // so we must check all rotations

        string str = s + s;   // doubling string to simulate rotations
        int j = 0;

        // sliding window of size n over s+s
        // window initially covered by first loop

        while (i < str.size()) {
            // add new character entering window
            if (i % 2 == 0) {
                if (str[i] == '0')
                    a++;
                else
                    b++;
            } else {
                if (str[i] == '1')
                    a++;
                else
                    b++;
            }

            // remove character leaving window
            if (j % 2 == 0) {
                if (str[j] == '0')
                    a--;
                else
                    b--;
            } else {
                if (str[j] == '1')
                    a--;
                else
                    b--;
            }

            // update answer for this rotation window
            ans = min({ans, a, b});

            i++;
            j++;
        }

        return ans;
    }
};