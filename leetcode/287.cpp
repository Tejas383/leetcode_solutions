#include <bits/stdc++.h>

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] == arr[i + 1]) 
                return arr[i];
        }
        return 0;
    }
};