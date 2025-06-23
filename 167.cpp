#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++)
            for (int j = i + 1; j < numbers.size(); j++)
                if (numbers[i] + numbers[j] == target)
                    return {i + 1, j + 1};
        return {-1, -1};
    }
};