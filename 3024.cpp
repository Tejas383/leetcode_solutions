#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        if ((nums[0] == nums[1]) && (nums[0] == nums[2]))
            return "equilateral";
        if(!checkSum(nums[0], nums[1], nums[2]))
            return "none";
        if ((nums[0] == nums[1]) || (nums[1] == nums[2]) || (nums[2] == nums[0]))
            return "isosceles";
        return "scalene";
    }
    bool checkSum(int a, int b, int c) {
        if ((a + b > c) && (b + c > a) && (c + a > b))
            return true;
        return false;
    }
};