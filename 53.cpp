#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Kadane's algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > ans) ans = sum;
            if (sum < 0) sum = 0; 
        }
        return ans;
    }
};