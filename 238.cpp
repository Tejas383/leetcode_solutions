#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i = 0;
        vector<int> prefix(nums.size(), 0);

        int j = nums.size() - 1;
        vector<int> suffix(nums.size(), 0);

        vector<int> ans(nums.size(), 0);

        while (i < nums.size() && j >= 0) {
            if (i == 0) 
                prefix[i] = 1;
            else 
                prefix[i] = prefix[i - 1] * nums[i - 1];
            
            if (j == nums.size() - 1)
                suffix[j] = 1;
            else 
                suffix[j] = suffix[j + 1] * nums[j + 1];

            i++;
            j--;
        }

        for (int el = 0; el < nums.size(); el++) {
            ans[el] = prefix[el] * suffix[el];
        }

        return ans;
    }
};