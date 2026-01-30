#include <queue>
using namespace std;
class MedianFinder {
public:
    // Max-heap to store the smaller half of the numbers
    priority_queue<int> maxh;
    
    // Min-heap to store the larger half of the numbers
    priority_queue<int, vector<int>, greater<int>> minh;
   
    // Constructor
    MedianFinder() { }
    
    // Function to add a number into the data structure
    void addNum(int num) {
        // Step 1: Push into max-heap first
        maxh.push(num);
        
        // Step 2: Balance by moving the largest element from maxh to minh
        minh.push(maxh.top());
        maxh.pop();
        
        // Step 3: Ensure maxh always has equal or more elements than minh
        if(maxh.size() < minh.size()) {
            maxh.push(minh.top());
            minh.pop();
        }
    }
    
    // Function to find the median
    double findMedian() {
        // Case 1: If both heaps have equal size, median is average of tops
        if(maxh.size() == minh.size()) 
            return (double)(maxh.top() + minh.top()) / 2;
        
        // Case 2: Otherwise, maxh has one extra element → median is its top
        return maxh.top();
    }
};

/**
 * Usage:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */