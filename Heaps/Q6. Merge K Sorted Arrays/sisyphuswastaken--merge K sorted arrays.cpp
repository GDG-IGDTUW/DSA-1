class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < m; i++) {
            minHeap.push(nums1[i]);
        }

        for (int i = 0; i < n; i++) {
            minHeap.push(nums2[i]);
        }

        int idx = 0;
        while (!minHeap.empty()) {
            nums1[idx++] = minHeap.top();
            minHeap.pop();
        }
    }
};
