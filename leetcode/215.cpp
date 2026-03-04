#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        for (int i = 0; i < k-1; i++) {
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }
        return nums.front();
    }
};

// we are a=not using the quickSelect algorithm as given below, since
// the worst case time complexity of quickSelect is O(N^2)
// while that of heap is O(n.logn)

// class Solution {
// public:
//     void quickSort(vector<int>& arr, int start, int end, int index) {
//         int pivot = arr[end];
//         int i = start;

//         for (int j = start; j < end; j++) {
//             if (arr[j] < pivot) {
//                 swap(arr[i], arr[j]);
//                 i++;
//             }
//         }
//         swap(arr[i], arr[end]);

//         if (i == (index)) return;

//         else if (index < i) 
//             quickSort(arr, start, i - 1, index);
//         else 
//             quickSort(arr, i + 1, end, index);
//     }

//     int findKthLargest(vector<int>& nums, int k) {
//         int index = nums.size() - k;
//         quickSort(nums, 0, nums.size() - 1, index);
//         return nums[index];
//     }
// };