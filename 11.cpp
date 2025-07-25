#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int vol = 0;

        int i = 0;
        int j = height.size() - 1;

        while (i < j) {
            vol = max(vol, min(height[i], height[j]) * (j - i));
            if (height[i] > height[j]) j--;
            else i++;
        }

        return vol;
    }
};