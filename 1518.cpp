#include iostream
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles >= numExchange) {
            int quo = numBottles / numExchange;
            int rem = numBottles % numExchange;
            ans += quo;
            numBottles = quo + rem;
        }
        return ans;
    }
};