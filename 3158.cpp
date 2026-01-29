#include <bits/stdc++.h>

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        map<int, int> freq;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            if (freq[nums[i]] == 2)
                ans ^= nums[i];
        }
        return ans;
    }
};