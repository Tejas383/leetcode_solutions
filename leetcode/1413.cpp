#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        int minEl = 0;

        for (int el : nums) {
            sum += el;
            minEl = min(sum, minEl);
        }

        return 1 - minEl;
    }
};