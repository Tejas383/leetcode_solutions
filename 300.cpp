#include <bits/stdc++.h>

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for (int num : nums) {
            if (lis.empty() || num > lis[lis.size() - 1]) {
                lis.push_back(num);
                continue;
            }
            
            int start = 0;
            int end = lis.size() - 1;
            int mid = (start + end) / 2;
            while (start < end) {
                mid = (start + end) / 2;

                if (num <= lis[mid])
                    end = mid;
                else 
                    start = mid + 1;
            }
            lis[start] = num;
        }

        return lis.size();
    }
};