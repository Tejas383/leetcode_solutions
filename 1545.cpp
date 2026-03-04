#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        string prev = "0";
        string next = "";
        for (int i = 0; i < n; i++) {
            next = prev + "1";
            string temp = "";
            for (char c : prev) {
                if (c == '1')
                    temp += '0';
                else 
                    temp += '1';
            }
            reverse(temp.begin(), temp.end());
            next += temp;
            prev = next;
        }
        // cout << prev;
        return prev[k - 1];
    }
};