#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        while (j < nums.size()) {
            while (i < j && nums[i] != 0) 
                i++;
            while (j < nums.size() - 1 && nums[j] == 0)
                j++;
            
            if (nums[i] == 0 && nums[j] != 0)
                swap(nums[i++], nums[j]);
            
            j++;
        }
    }
};