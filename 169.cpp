#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        int n = nums.size() / 2;
        for (int el : nums) {
            count[el]++;
            if (count[el] > n) return el;
        }
        return 0;
    }
};