#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > target && nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) 
                    continue;
                int left = j + 1;
                int right = nums.size() - 1;
                long long sum = (long long)nums[i] + nums[j];
                long long comp = (long long)target - sum;
                while (left < right) {
                    if (nums[left] + nums[right] > comp) 
                        right--;
                    else if (nums[left] + nums[right] < comp)
                        left++;
                    else {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        int l = nums[left];
                        int r = nums[right];
                        while (left < right && nums[left] == l)
                            left++;
                        while (left < right && nums[right] == r)
                            right--;
                    }
                }
            }
        }

        return ans;
    }
};