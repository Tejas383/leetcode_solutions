#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int calcSum = 0;
        int n = nums.size();
        int expSum = n * (n + 1) / 2;
        for (auto i : nums) {
            calcSum += i;
        }
        return expSum - calcSum;
    }
};