class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        // Max-heap using priority_queue
        priority_queue<pair<int, pair<int, int>>> pq;

        // Iterate over all points
        for (int i = 0; i < points.size(); i++) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if (pq.size() < k) {
                pq.push({dist, {points[i][0], points[i][1]}});
            } else {
                if (dist < pq.top().first) {
                    pq.pop();
                    pq.push({dist, {points[i][0], points[i][1]}});
                }
            }
        }

        // Extract points from the priority_queue
        while (!pq.empty()) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }

        // Since the order might differ, reverse the result
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
