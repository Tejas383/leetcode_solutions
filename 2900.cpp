#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;

        int index = 0;
        ans.push_back(words[index]);
        for (int i = 0; i < words.size(); i++) {
            if (groups[i] != groups[index]) {
                index = i;
                ans.push_back(words[index]);
            }
        }

        return ans;
    }
};