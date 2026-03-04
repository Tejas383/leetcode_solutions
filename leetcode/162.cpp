#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int left = (mid == 0) ? INT_MIN : nums[mid - 1];
            int right = (mid == nums.size() - 1) ? INT_MIN : nums[mid + 1];

            if (left < nums[mid] && right < nums[mid]) 
                return mid;
            if (right > nums[mid]) 
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return 0;
    }
};