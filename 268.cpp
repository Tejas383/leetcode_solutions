#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor_of_indices = 0, xor_of_elements = 0;
        // a ^ a = 0
        for (int i = 0; i < nums.size(); i++) {
            xor_of_indices = xor_of_indices ^ i;
            xor_of_elements = xor_of_elements ^ nums[i];
        }
        xor_of_indices = xor_of_indices ^ nums.size();
        return xor_of_indices ^ xor_of_elements;
        // the element missing in the array is : xor_of_indices ^ xor_of_elements
    }
};