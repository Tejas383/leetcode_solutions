#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z, o, t;
        z = o = t = 0;
        for (int n : nums) {
            if (n == 0) z++;
            else if (n == 1) o++;
            else t++;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i < z) nums[i] = 0;
            else if (i < z + o) nums[i] = 1;
            else nums[i] = 2;
        }
    }
};