#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<int> vec;
        vector<string> ans;

        int index = 0;
        vec.push_back(index);
        for (int i = 0; i < words.size(); i++) {
            if (groups[i] != groups[index]) {
                index = i;
                vec.push_back(index);
            }
        }

        for (int val : vec) {
            ans.push_back(words[val]);
        }

        return ans;
    }
};