#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int el : nums) {
            if (nums[i] != el) {
                i++;
                nums[i] = el;
            }
        }
        return i + 1;
    }
};