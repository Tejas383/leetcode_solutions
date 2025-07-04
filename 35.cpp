#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target < nums[0])
            return 0;
        
        int low, mid, high;
        low = 0;
        high = nums.size() - 1;
        mid = -1;
        while (high >= low) {
            mid = (low + high) / 2;
            if (target < nums[mid]) {
                high = mid - 1;
            } else if (target > nums[mid]) {
                low = mid + 1;
            } else {
                return mid;
            }
        }
        if (target > nums[mid]) {
            return mid + 1;
        }
        return mid;
        // OR
        // return low;
    }
};