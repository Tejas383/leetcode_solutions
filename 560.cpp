#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSum;
        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum == k) cnt++;
            int val = sum - k;
            if (prefixSum.count(val))
                cnt += prefixSum[val];
            prefixSum[sum]++;
        }
        return cnt;
    }
};