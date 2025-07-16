#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if ((i == nums.size() - 1) && (first < second && second < num))
                return true;
            if (num <= first) first = num;
            else if (num <= second) second = num;
            else 
                if (first < second < num) return true;
            }
        return false;
    }
};