#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> merge(vector<int> left, vector<int> right) {
        vector<int> merged;
        int i = 0;
        int j = 0;

        while (i < left.size() && j < right.size()) {
            if (left[i] > right[j]) {
                merged.push_back(right[j]);
                j++;
            } else {
                merged.push_back(left[i]);
                i++;
            }
        }
        while (i < left.size()) {
            merged.push_back(left[i]);
            i++;
        }
        while (j < right.size()) {
            merged.push_back(right[j]);
            j++;
        }
        
        return merged;
    }

    vector<int> mergeSort(vector<int>&arr, int start, int end) {
        if (start == end) 
            return {arr[start]};
        
        int mid = (start + end) / 2;
        vector<int> left = mergeSort(arr, start, mid); 
        vector<int> right = mergeSort(arr, mid + 1, end);

        return merge(left, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};