#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void quickSort(vector<int>&arr, int start, int end) {
        if (start >= end) return;

        int randomIndex = start + rand() % (end - start + 1);
        swap(arr[randomIndex], arr[end]);

        int pivot = arr[end];
        int i = start;
        
        for (int j = start; j < end; j++) {
            if (arr[j] < pivot) {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[end]);

        quickSort(arr, start, i - 1);
        quickSort(arr, i + 1, end);
    }

    vector<int> quickSortArray(vector<int>& nums) {
        vector<int> ans = nums;

        quickSort(ans, 0, ans.size() - 1);

        return ans;
    }
};