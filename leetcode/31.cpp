#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinIndex(vector<int>& nums, int start) {
        int min = start;
        for (int j = start + 1; j < nums.size(); j++) {
            if (nums[j] < nums[min] && nums[j] > nums[start - 1]) {
                min = j;
            }
        }
        return min;
    }
    void nextPermutation(vector<int>& nums) {
        bool max = true;
        for (int i = nums.size() - 1; i > 0; i--) {
            int el;
            if (nums[i] > nums[i - 1]) {
                max = false;
                int min = findMinIndex(nums, i);
                swap(nums[i - 1], nums[min]);
                sort(nums.begin() + i, nums.end());
                break;
            }
        }
        if (max) {
            reverse(nums.begin(), nums.end());
        }
    }
};