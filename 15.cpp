#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int low = i + 1;
            int high = nums.size() - 1;
            while (low < high) {
                int sum = nums[i] + nums[low] + nums[high];
                if (sum < 0)
                    low++;
                else if (sum > 0) 
                    high--;
                else {
                    ans.push_back({nums[i], nums[low], nums[high]});
                    int l = nums[low];
                    int h = nums[high];
                    while (low < high && nums[low] == l)
                        low++;
                    while (low < high && nums[high] == h)
                        high--;
                }
            }
        }

        return ans;
    }
};