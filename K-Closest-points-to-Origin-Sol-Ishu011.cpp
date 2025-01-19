//Heaps\Q3) K Closest Points to Origin
//Approach 2: Quickselect
//-Use the Quickselect algorithm, which is based on the idea of partitioning (like Quicksort).
//-Partition the array such that the first k elements are the k closest points. This avoids the overhead of maintaining a heap.
//Time Complexity: O(n) on average due to partitioning. and Space Complexity: O(1)
//Code:
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto distance = [](const vector<int>& point) {
            return point[0] * point[0] + point[1] * point[1];
        };

        // Partition function for quickselect
        auto partition = [&](int left, int right, int pivotIndex) {
            // Calculate the distance of the pivot point
            int pivotDistance = distance(points[pivotIndex]);
            // Move pivot element to the end
            swap(points[pivotIndex], points[right]);
            int storeIndex = left;

            // Compare all points with the pivot distance and rearrange
            for (int i = left; i < right; i++) {
                if (distance(points[i]) < pivotDistance) {
                    swap(points[storeIndex], points[i]);
                    storeIndex++;
                }
            }
            // Move pivot to its final sorted position
            swap(points[storeIndex], points[right]);
            return storeIndex; // Return the position of the pivot
        };

        int left = 0, right = points.size() - 1;
        // Quickselect logic: Narrow down the range to find the first k closest points
        while (left <= right) {
            // Choose a random pivot index between left and right
            int pivotIndex = left + rand() % (right - left + 1);
            // Partition the array around the pivot
            int newPivotIndex = partition(left, right, pivotIndex);

            // Check if we have partitioned enough to get the k closest points
            if (newPivotIndex == k) {
                break; // Found the k closest points
            } else if (newPivotIndex < k) {
                left = newPivotIndex + 1; // Search the right part of the array
            } else {
                right = newPivotIndex - 1; // Search the left part of the array
            }
        }

        // Return the first k points after partitioning
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};
