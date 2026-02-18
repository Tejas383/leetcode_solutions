class Solution {
public:
    static bool comp(vector<int>& a, vector<int> &b) {
        if (a[0] == b[0])
            return a[1] > b[1];
        else 
            return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        
        vector<int> lis;

        for (auto envelope : envelopes) {
            if (lis.empty() || lis[lis.size() - 1] < envelope[1]) 
                lis.push_back(envelope[1]);
            else {
                int start = 0;
                int end = lis.size() - 1;
                while (start < end) {
                    int mid = (start + end) / 2;
                    
                    if (envelope[1] <= lis[mid]) 
                        end = mid;
                    else 
                        start = mid + 1;
                }
                lis[start] = envelope[1];
            }
        }

        return lis.size();
    }
};