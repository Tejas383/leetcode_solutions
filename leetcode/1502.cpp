#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        int maxEl = *max_element(arr.begin(), arr.end());
        int minEl = *min_element(arr.begin(), arr.end());

        if ((maxEl - minEl) % (n - 1) != 0)
            return false;
        
        int d = (maxEl - minEl) / (n - 1);
        if (d == 0) {
            for (int el : arr) {
                if (el != minEl)
                    return false;
            }
            return true;
        }

        vector<bool> pres(n, false);
        for (int el : arr) {
            if ((el - minEl) % d != 0) {
                return false; 
            }
            int pos = (el - minEl) / d;
            if (pos >= n || pres[pos])
                return false;
            pres[pos] = true;
        }

        return true;
    }
};