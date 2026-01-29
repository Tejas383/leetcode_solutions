#include <bits/stdc++.h>

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int i = 1;
        while (i < nums.size()) {
            if (nums[i] == nums[i - 1]) {
                ans ^= nums[i];
            }
            i++;
        }
        return ans;
    }
};

approach name