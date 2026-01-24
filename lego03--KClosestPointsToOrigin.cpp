class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<vector<int>> ans;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k; i++) {
            int d = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.push({d, i});
        }
        for (int i = k; i < n; i++) {
            int d = points[i][0] * points[i][0] + points[i][1] * points[i][1];

            if (d < pq.top().first) {
                pq.push({d, i});
                pq.pop();
            }
        }

        while (!pq.empty()) {
            int ind = pq.top().second;

            ans.push_back(points[ind]);
            pq.pop();
        }
        return ans;
    }
};
