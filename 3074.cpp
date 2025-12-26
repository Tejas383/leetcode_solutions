#include <bits/stdc++.h>

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int num = 0;
        for (int i : apple) 
            num += i;
        
        sort(capacity.begin(), capacity.end());
        reverse(capacity.begin(), capacity.end());

        int sum = 0;
        for (int i = 0; i < capacity.size(); i++) {
            sum += capacity[i];
            if (sum >= num)
                return i + 1;
        }

        return 0;
    }
};