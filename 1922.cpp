#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long calc_pow(long long base, long long exp, long long mod) {
        long long ans = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1)
                ans = (ans * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long mod = 1e9 + 7;
        long long even_pos = (n + 1) / 2;
        long long odd_pos = n / 2;

        long long ans = (calc_pow(5, even_pos, mod) * calc_pow(4, odd_pos, mod)) % mod;
        return ans;
    }
};
