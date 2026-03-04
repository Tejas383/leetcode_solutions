#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3)
            return false;
        
        bool vow = false;
        bool cons = false;
        map<char, int> vowels = {{'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}, {'A', 1}, {'E', 1}, {'I', 1}, {'O', 1}, {'U', 1}};
        for (char ch : word) {
            if (!isalnum(ch)) return false;
            if (vowels.count(ch)) vow = true;
            else if (!isdigit(ch)) cons = true;
        }

        return (vow && cons);
    }
};