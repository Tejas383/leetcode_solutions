#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        map<int, vector<int>> m;
        // map = {count -> {numbers}}

        for (auto num : arr) {
            int c = 0;
            int n = num;
            while (n > 0) {
                if (n & 1)
                    c++;
                n = n >> 1;
            }
            m[c].push_back(num);
        }

        vector<int> ans;
        for (auto p : m) {
            for (auto i : p.second)
                ans.push_back(i);
        }

        return ans;
    }
};