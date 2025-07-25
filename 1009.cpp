#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0)
            return 1;
        
        int power = 0;
        while (n >= (1 << power))
            power++;
        int comp = ((1 << power) - 1) - n;
        return comp;
    }
};