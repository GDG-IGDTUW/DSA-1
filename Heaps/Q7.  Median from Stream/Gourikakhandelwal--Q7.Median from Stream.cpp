#include <queue>
using namespace std;

class MedianFinder {
public:
    // Max-heap (stores the smaller half of numbers, largest element at the top)
    priority_queue<int> maxh;

    // Min-heap (stores the larger half of numbers, smallest element at the top)
    priority_queue<int, vector<int>, greater<int>> minh;

    // Constructor (no special initialization needed)
    MedianFinder() {}

    // Add a number into the data structure
    void addNum(int num) {
        // Step 1: Push new number into max-heap
        maxh.push(num);

        // Step 2: Balance by moving the largest element from maxh into minh
        minh.push(maxh.top());
        maxh.pop();

        // Step 3: Ensure maxh always has equal or one more element than minh
        if (maxh.size() < minh.size()) {
            maxh.push(minh.top());
            minh.pop();
        }
    }

    // Find the median of all numbers added so far
    double findMedian() {
        // Case 1: If heaps are equal size, median is the average of both tops
        //double to accommodate non-integer median
        if (maxh.size() == minh.size()) {
            return (double)(maxh.top() + minh.top()) / 2;
        }
        // Case 2: Otherwise, maxh has one extra element → median is its top
        return maxh.top();
    }
};

/**
 * Usage example:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */