#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;
        for (int num : nums) {
            if (num <= first) first = num;
            else if (num <= second) second = num;
            else // first < second < num
                return true;
            }
        return false;
    }
};