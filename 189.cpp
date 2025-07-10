#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k >= nums.size())
            k %= nums.size();
        
        vector<int> ans;
        for (int i = nums.size() - k; i < nums.size(); i++) {
            ans.push_back(nums[i]);
        }
        for (int i = 0; i < nums.size() - k; i++) {
            ans.push_back(nums[i]);
        }
        nums = ans;
    }
};