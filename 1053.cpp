#include <bits/stdc++.h>

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        vector<int> ans = arr;
        for (int i = arr.size() - 2; i >= 0; i--) {
            int elt = arr[i];
            int max = -1;
            int index = -1;
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[j] < elt && arr[j] > max) {
                    max = arr[j];
                    index = j;
                }
            }
            if (index != -1) {
                swap(ans[i], ans[index]);
                break;
            }
        }
        return ans;
    }
};