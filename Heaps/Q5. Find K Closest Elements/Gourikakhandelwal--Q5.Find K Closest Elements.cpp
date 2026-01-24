#include <bits/stdc++.h>   // Includes all standard C++ libraries
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Result vector to store the k closest elements
        vector<int> v;

        // Max-heap (priority queue) that stores pairs: (distance from x, element value)
        // By default, priority_queue in C++ is a max-heap, so the element with the largest "distance" will be at the top.
        priority_queue<pair<int,int>> pq;
        
        // Step 1: Initialize the heap with the first k elements
        // We calculate the absolute difference between each element and x,
        // and push it along with the element itself into the heap.
        for(int i = 0; i < k; i++) {
            pq.push({abs(arr[i] - x), arr[i]});
        }
        
        // Step 2: Process the remaining elements in the array
        // For each new element, check if it is closer to x than the farthest element currently in the heap.
        for(int i = k; i < arr.size(); i++) {
            // pq.top() gives us the element with the largest distance (the "worst" candidate so far).
            // If the current element is closer to x than that, we replace it.
            if(pq.top().first > abs(arr[i] - x)) {
                pq.pop();  // Remove the farthest element
                pq.push({abs(arr[i] - x), arr[i]});  // Insert the closer element
            }
        }
        
        // Step 3: Extract all elements from the heap
        // At this point, the heap contains the k closest elements to x.
        while(!pq.empty()) {
            v.push_back(pq.top().second);  // Store the element value (second of the pair)
            pq.pop();
        }
        
        // Step 4: Sort the result in ascending order
        // The problem statement usually requires the output to be sorted.
        sort(v.begin(), v.end());
        
        // Step 5: Return the final list of k closest elements
        return v;
    }
};