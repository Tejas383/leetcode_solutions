#include <vector>
using namespace std;

// Precompute row-wise and column-wise sums, then validate candidates
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> row(mat.size(), 0);
        vector<int> col(mat[0].size(), 0);

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1)
                    row[i]++, col[j]++;
            }
        }

        int sp = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1)
                    sp++;
            }
        }

        return sp;
    }
};