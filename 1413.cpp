#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        vector<int> prefix(nums.size() + 1);
        prefix[0] = 0;

        for (int i = 1; i <= nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        int min = *min_element(prefix.begin(), prefix.end());

        return (min <= 0) ? abs(min) + 1 : min;
    }
};