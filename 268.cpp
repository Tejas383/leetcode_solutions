#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] < nums.size() && nums[i] != nums[nums[i]]) 
                swap(nums[i], nums[nums[i]]);
            else 
                i++;
        }
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != j)
                return j;
        }
        return nums.size();
    }
};