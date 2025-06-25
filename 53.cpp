#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int ans = INT_MIN;
            int sum;
            for (int i = 0; i < nums.size(); i++) {
                for (int j = i; j < nums.size(); j++) {
                    sum = 0;
                    for (int k = i; k <= j; k++) {
                        sum += nums[k];
                        if (sum > ans) ans = sum;
                    }
                }
            }
            return ans;
        }
    };
}