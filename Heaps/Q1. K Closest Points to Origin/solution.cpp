
/*
Intuition:
-----------
We need the k closest points to the origin.
Instead of sorting all points (O(n log n)), we can maintain a max-heap
of size k that stores the closest points found so far.

Why max-heap?
- If heap size exceeds k, we remove the farthest point.
- This ensures we only keep the k closest points at all times.

We compare points using squared distance (x^2 + y^2)
to avoid unnecessary sqrt computation.

Algorithm:
-----------
1. Create a max-heap storing pair {distance, point}.
2. Traverse all points:
    - Compute squared distance.
    - Push into heap.
    - If heap size > k, pop the top (farthest).
3. Extract remaining k elements from heap.
4. Return them.

Time Complexity:
----------------
O(n log k)
- Each insertion/removal from heap takes log k.
- We process n points.

Space Complexity:
-----------------
O(k)
- Heap stores at most k elements.
*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        // Max heap: stores {distance, {x, y}}
        priority_queue<pair<int, vector<int>>> maxHeap;
        
        for (auto &point : points) {
            int x = point[0];
            int y = point[1];
            
            int dist = x*x + y*y;  // squared distance
            
            maxHeap.push({dist, point});
            
            if (maxHeap.size() > k) {
                maxHeap.pop();  // remove farthest
            }
        }
        
        vector<vector<int>> result;
        
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return result;
    }
};
