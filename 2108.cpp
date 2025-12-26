#include <bits/stdc++.h>

class Solution {
public:
    bool palindrome(string str) {
        int i = 0;
        int j = str.size() - 1;
        while (i < j) {
            if (str[i] == str[j]) {
                i++, j--;
            } else
                return false;
        }
        return true;
    }

    string firstPalindrome(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            if (palindrome(words[i])) 
                return words[i];
        }
        return "";
    }
};