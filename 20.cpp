#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> vec;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                vec.push(s[i]);
            }
            else {
                if (s[i] == ')') {
                    if (vec.empty()) return false;
                    else {
                        if (vec.top() == '(') {
                            vec.pop();
                        } else {
                            return false;
                        }
                    }
                } else if (s[i] == ']') {
                    if (vec.empty()) return false;
                    else {
                        if (vec.top() == '[') {
                            vec.pop();
                        } else {
                            return false;
                        }
                    }
                } else if (s[i] == '}') {
                    if (vec.empty()) return false;
                        else {
                        if (vec.top() == '{') {
                            vec.pop();
                        } else {
                            return false;
                        }
                    }
                }
            }
        }
        if (!vec.empty()) return false;
        return true;
    }
};