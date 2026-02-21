class Solution {
public:
    int countSetBits(int n) {
        int count = 0;

        while (n > 0) {
            count += n & 1;
            n = n >> 1;
        }

        return count;
    }

    int countPrimeSetBits(int left, int right) {
        int ans = 0;

        for (int i = left; i <= right; i++) {
            int setBits = countSetBits(i);
            if (
                setBits == 2 || 
                setBits == 3 || 
                setBits == 5 || 
                setBits == 7 || 
                setBits == 11 || 
                setBits == 13 || 
                setBits == 17 || 
                setBits == 19
            )
                ans++;
        }

        return ans;
    }
};