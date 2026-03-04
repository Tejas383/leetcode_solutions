#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> freq;
        for (int i = 0; i < arr.size(); i++) {
            freq[arr[i]]++;
        }
        int ans = -1;
        for (auto el : freq) {
            if ((el.first == el.second) && (el.first > ans))
                ans = el.first;
        }
        return ans;
    }
};