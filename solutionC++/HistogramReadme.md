//solution of max area in Histogram (C++).

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); // sentinel
        stack<int> st;
        long long maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, 1LL * height * width);
            }
            st.push(i);
        }
        return (int)maxArea;
    }
};
