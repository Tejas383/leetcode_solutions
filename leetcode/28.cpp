#include <string>
using namespace std;

// Approach Name: Naive String Matching (Brute Force Substring Search)
// Time complexity = O(n * m)
// Space complexity = O(1)

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0;

        while (i < haystack.size()) {
            int j = 0;
            int idx = i;

            while (j < needle.size()) {
                if (haystack[i] != needle[j])
                    break;

                i++, j++;

                if (j == needle.size())
                    return idx;
            }
            i = idx + 1;
        }
        return -1;
    }
};