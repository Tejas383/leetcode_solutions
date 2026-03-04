class Solution {
public:
    int differenceOfSums(int n, int m) {
        int total = n * (n + 1) / 2;
        int a = n / m;
        int num2 = a * (a + 1) * m / 2;
        int num1 = total - num2;

        return (num1 - num2);
    }
};