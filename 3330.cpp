#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int count = 1;
        int i = 0;
        int j = 1;
        while (i < word.size()) {
            if (word[j] == word[i]) {
                count++;
                j++;
            } else {
                i = j;
                j++;
            }
        }
        return count;
    }
};