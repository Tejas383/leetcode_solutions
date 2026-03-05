#include <string>
using namespace std;

// Approach Name: Greedy – Alternating Pattern Check
// Time Complexity = O(n)
// Space Complexity = O(1)

class Solution {
public:
    int minOperations(string s) {
        int a, b;
        a = b = 0;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == '0')
                a++;
            else 
                b++;
            i++;
            if (i < s.size()) {
                if (s[i] == '1')
                    a++;
                else 
                    b++;
                i++;
            }
        }

        return min(a, b);
    }
};