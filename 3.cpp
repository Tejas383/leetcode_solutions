#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> freq;
        int start = 0;
        int ans = 0;
        int len = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!freq.count(s[i]) || freq[s[i]] == 0) {
                freq[s[i]] = 1;
                len++;
            }
            else { // freq[s[i]] == 1
                while (true) {
                    freq[s[start]] = 0;
                    len--;
                    if (s[start] == s[i]) {
                        start++;
                        len++;
                        break;
                    }
                    start++;
                }
                freq[s[i]] = 1;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};