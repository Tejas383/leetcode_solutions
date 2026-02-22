class Solution {
public:
    int binaryGap(int n) {
        while (n > 0 && ((n & 1) == 0))
            n = n >> 1;
        
        if (n == 0 || n == 1)
            return 0;

        n = n >> 1;

        int maxLen = 1;
        int len = 1;
        while (n > 0) {
            if ((n & 1) == 0)
                len++;
            else
                len = 1;
            maxLen = max(len, maxLen);
            n = n >> 1;
        }

        return maxLen;
    }
};