#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for (int i = 0; i < s.size(); i++) {
            if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
                str += s[i]; 
            }
        }

        for (int i = 0; i < str.size() / 2; i++) {
            if (tolower(str[i]) != tolower(str[str.size() - i - 1])) return false;
        }
        return true;
    }
};