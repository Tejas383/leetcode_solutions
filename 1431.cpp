#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size());
        int maxi = 0;
        for (int i = 0; i < candies.size(); i++) {
            maxi = max(maxi, candies[i]);
        }
        for (int i = 0; i < candies.size(); i++) {
            result[i] = (candies[i] + extraCandies) >= maxi;
        }
        return result;
    }
};