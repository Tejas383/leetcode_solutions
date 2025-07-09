class Solution {
public:
    int find(vector<int>& nums, int target, int start, int end) {
        while (start <= end) {
            int mid = (start + end) / 2;
            if (target > nums[mid]) {
                start = mid + 1;
            } else if (target < nums[mid]) {
                end = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            if (target == nums[0])
                return 0;
            else 
                return -1;
        }
        
        if (nums[0] < nums[nums.size() - 1])
            return find(nums, target, 0, nums.size() - 1);

        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[mid] < nums[high])
                high = mid;
            else 
                low = mid + 1;
        }
        int min = mid;

        if (target >= nums[0]) 
            return find(nums, target, 0, min - 1);
        
        return find(nums, target, min, nums.size() - 1);
    }
};