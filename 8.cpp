#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int num = 0;
        int i = 0;
        while (i < s.size() && (s[i] == ' '))
            i++;

        bool neg = false;
        if (s[i] == '-') {
            neg = true;
            i++;
        } else if (s[i] == '+')
            i++;
        
        while (i < s.size() && isdigit(s[i])) {
            int n = s[i] - '0';
            if (!neg && ((num > INT_MAX / 10) || (num == INT_MAX / 10 && n > 7)))
                return INT_MAX;
            if (neg && ((num > INT_MAX / 10) || (num == INT_MAX / 10 && n > 7)))
                return INT_MIN;
            
            num = num * 10 + n;
            i++;
        }

        num = (neg) ? -num : num;
        return num;
    }
};