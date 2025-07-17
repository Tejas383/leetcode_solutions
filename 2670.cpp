#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int> diff(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            set<int> prefix;
            for (int j = 0; j <= i; j++) {
                prefix.insert(nums[j]);
            }
            set<int> suffix;
            for (int j = i + 1; j < nums.size(); j++) {
                suffix.insert(nums[j]);
            }
            diff[i] = prefix.size() - suffix.size();
        }
        return diff;
    }
};