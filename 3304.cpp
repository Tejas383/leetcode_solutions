#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while (k > word.length()) {
            string app = "";
            for (int i = 0; i < word.size(); i++) {
                int val = (int)word[i];
                val++;
                char ch = val;
                app += ch;
            }
            word += app;
        }
        return word[k-1];
    }
};