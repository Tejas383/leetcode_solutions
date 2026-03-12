#include <vector>
using namespace std;

// Approach Name: Two Pointers (Opposite Ends / Partition-based)
// Time complexity = O(n)
// Space complexity = O(n)

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size() - 1;

        while (i <= j) {
            while (i < nums.size() && nums[i] != val)
                i++;
            while (j >= 0 && nums[j] == val)
                j--;
            if (i >= j)
                break;
            swap(nums[i], nums[j]);
        }

        return i;
    }
};