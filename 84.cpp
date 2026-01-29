#include <bits/stdc++.h>

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;

        vector<int> pseIdx(heights.size(), -1);
        for (int i = 0; i < heights.size(); i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            if (!s.empty()) 
                pseIdx[i] = s.top();
            s.push(i);
        }

        while (!s.empty())
            s.pop();
        
        vector<int> nseIdx(heights.size(), heights.size());
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            if (!s.empty()) 
                nseIdx[i] = s.top();
            s.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            int area = (nseIdx[i] - pseIdx[i] - 1) * heights[i];
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }
};