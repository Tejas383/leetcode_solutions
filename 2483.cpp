#include <bits/stdc++.h>

class Solution {
public:
    int bestClosingTime(string customers) {
        int idx;
        int len = customers.size();

        string rev = customers;
        reverse(rev.begin(), rev.end());

        vector<int> preN;
        preN.push_back(0);
        vector<int> sufY;
        sufY.push_back(0);

        for (int i = 1; i <= len; i++) {
            if (customers[i - 1] == 'N')
                preN.push_back(preN[i - 1] + 1);
            else 
                preN.push_back(preN[i - 1]);

            if (rev[i - 1] == 'Y')
                sufY.push_back(sufY[i - 1] + 1);
            else 
                sufY.push_back(sufY[i - 1]);
        }

        reverse(sufY.begin(), sufY.end());

        int minVal = INT_MAX;
        for (int i = 0; i <= len; i++) {
            if ((preN[i] + sufY[i]) < minVal) {
                minVal = preN[i] + sufY[i];
                idx = i;
            }
        }

        return idx;
    }
};