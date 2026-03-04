#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = 0;
        for (int i = 1; i < nums.size(); i++) {
            rightSum += nums[i];
        }

        int i = 0;
        while (i < nums.size()) {
            if (i == 0 && rightSum == 0)
                return 0;
            if (i > 0) {
                leftSum += nums[i - 1];
                rightSum -= nums[i];
            }
            if (leftSum == rightSum)
                return i;
            i++;
        }
        
        return -1;
    }
};