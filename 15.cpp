#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }

        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                break;
            
            for (int j = i + 1; j < nums.size(); j++) {
                int sum = nums[i] + nums[j];
                int comp = 0 - sum;
                if (mp.count(comp) && mp[comp] > j) {
                    vector<int> subans = {nums[i], nums[j], comp};
                    ans.push_back(subans);
                }
                j = mp[nums[j]];
            }
            i = mp[nums[i]];
        }
        return ans;
    }
};