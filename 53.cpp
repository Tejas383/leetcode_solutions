#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// KADANE'S ALGORITHM:
// Add each element to sum, update answer with max(sum, answer), 
// reset sum to 0 if it's negative (as it can't contribute to future maximum).
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int sum = 0;
        for (int el : nums) {
            sum += el;
            ans = max(sum, ans);
            sum = max(sum, 0);
        }
        return ans;
    }
};