#include <bits/stdc++.h>

class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int even, odd;
        even = odd = 0;
        for (int num : nums) {
            if (num % 2 == 0)
                even++;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i < even)
                nums[i] = 0;
            else 
                nums[i] = 1;
        }

        return nums;
    }
};