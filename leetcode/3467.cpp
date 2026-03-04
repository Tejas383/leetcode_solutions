#include <bits/stdc++.h>

class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int i = 0, j = 0;
        while (j < nums.size()) {
            if (nums[j] % 2 == 1) { // odd
                nums[j] = 1;
            } else { // even
                nums[j] = 0;
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }
        return nums;
    }
};