#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int h = nums.size() - 1;
        int m;
        while (true) {
            m = (l + h) / 2;
            if (m % 2 == 0) {
                if (m != 0 && nums[m - 1] == nums[m]) {
                    h = m;
                } else if (m != nums.size()-1 && nums[m + 1] == nums[m]) {
                    l = m;
                } else {
                    return nums[m];
                }
            } else {
                if (m != nums.size()-1 && nums[m + 1] == nums[m]) {
                    h = m - 1;
                } else if (m != 0 && nums[m - 1] == nums[m]) {
                    l = m + 1;
                } else {
                    return nums[m];
                }
            }
        }
        return 0;
    }
};