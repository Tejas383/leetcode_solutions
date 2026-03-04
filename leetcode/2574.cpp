#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        if (nums.empty())
            return {};
        if (nums.size() == 1) 
            return {0};
        
        vector<int> leftSum(nums.size());
        vector<int> rightSum(nums.size());

        int left = 0;
        leftSum[0] = 0;
        for (int i = 1; i < nums.size(); i++) {
            left += nums[i - 1];
            leftSum[i] = left;
        }

        int right = 0;
        rightSum[nums.size() - 1] = 0;
        for (int i = nums.size() - 2; i >= 0; i--) {
            right += nums[i + 1];
            rightSum[i] = right;
        }

        vector<int> diff(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            diff[i] = abs(leftSum[i] - rightSum[i]);
        }

        return diff;
    }
};