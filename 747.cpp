#include <bits/stdc++.h>

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());

        int elt;
        if (arr[arr.size() - 1] >= (2 * arr[arr.size() - 2]))
            elt = arr[arr.size() - 1];
        else 
            return -1;
        
        int index = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == elt)
                index = i;
        }

        return index;
    }
};