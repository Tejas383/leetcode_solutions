#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int count = 1;
        int i = 1;
        while (i < word.size()) {
            if (word[i - 1] == word[i]) {
                count++;
            }
            i++;
        }
        return count;
    }
};