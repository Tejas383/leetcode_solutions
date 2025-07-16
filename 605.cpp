#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        if (flowerbed.size() == 1) {
            if (flowerbed[0] == 0) return true;
            if (flowerbed[0] == 1 && n == 0) return true;
            return false;
        }
        
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0) {
                if (i == 0 && flowerbed[i + 1] == 0) {
                    cnt++;
                    flowerbed[i] = 1;
                } else if (i == flowerbed.size() - 1 && flowerbed[i - 1] == 0) {
                    cnt++;
                    flowerbed[i] = 1;
                } else {
                    if (i > 0 && i < flowerbed.size() - 1 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                        cnt++;
                        flowerbed[i] = 1;
                    }
                } 
            } else {
                i++;
            }
            if (cnt >= n) return true;
        }
        return false;
    }
};