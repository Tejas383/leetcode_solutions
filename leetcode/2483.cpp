#include <bits/stdc++.h>

class Solution {
public:
    int bestClosingTime(string customers) {
        int idx = 0;
        int curr_pen = 0;
        int min_pen = 0;

        for (int i = 1; i <= customers.size(); i++) {
            if (customers[i - 1] == 'Y')
                curr_pen--;
            else 
                curr_pen++;

            if (curr_pen < min_pen) {
                idx = i;
                min_pen = curr_pen;
            }
        }

        return idx;
    }
};