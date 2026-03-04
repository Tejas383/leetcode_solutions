#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int i = 0;
        int j = numbers.size() - 1;
        while (j > i) {
            int sum = numbers[i] + numbers[j];
            if (sum > target) j--;
            else if (sum < target) i++;
            else {
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            } 
        }
        return ans;
    }
};