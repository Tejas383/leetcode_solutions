#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> lastOne(n, -1);

        // find the index of last one that occurs in each row
        for (int i = 0; i < n; i++) {
            auto row = grid[i];
            for (int j = n - 1; j >= 0; j--) {
                if (row[j] == 1) {
                    lastOne[i] = j;
                    break;
                }
            }
        }

        // upon sorting , if the element is greater that idx, we cannot reach a solution
        vector<int> temp = lastOne;
        sort(temp.begin(), temp.end());
        for (int i = 0; i < n; i++) {
            if (temp[i] > i) {
                return -1;
            }
        }

        // greedy step:
        int count = 0;
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && lastOne[j] > i)
                j++;
            // this is can be placed at index i

            // bubble that row upward using adjacent swaps.
            while (j > i) {
                swap(lastOne[j], lastOne[j - 1]);
                count++;
                j--;
            }
        }
        // this guarantees minimum adjacent swaps because we always pull the closest valid row upward

        return count;
    }
};