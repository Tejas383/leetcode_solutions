#include <bits/stdc++.h>

class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> s_map;
        for (char c : s) 
            s_map[c]++;
        map<char, int> t_map;
        for (char c : t)
            t_map[c]++;
        
        char ans = ' ';
        for (auto p : t_map) {
            if (s_map[p.first] != p.second)
                ans = p.first;
        }
        return ans;
    }
};