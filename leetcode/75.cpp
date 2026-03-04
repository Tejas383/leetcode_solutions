#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Dutch National Flag Algorithm (DNF)
        int low, med, high;
        low = med = 0;
        high = nums.size() - 1;

        while (med <= high) {
            if (nums[med] == 0) {
                swap(nums[low], nums[med]);
                low++;
                med++;
            } else if (nums[med] == 1) {
                med++;
            } else { // (nums[med] == 2)
                swap(nums[med], nums[high]);
                high--;
            }
        }
    }
};