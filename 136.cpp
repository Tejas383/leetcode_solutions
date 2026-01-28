#include <bits/stdc++.h>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single = nums[0];
        int i = 1;
        while (i < nums.size())
            single = single ^ nums[i++];
        return single;
    }
};