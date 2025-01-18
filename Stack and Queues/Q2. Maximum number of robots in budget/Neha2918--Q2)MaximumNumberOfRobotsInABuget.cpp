class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int j = 0;                                // Start of the sliding window
        long long sum = 0;                        // Sum of running costs in the current window
        int ans = 0;                              // Stores the maximum number of robots
        deque<int> dq;                            // Monotonic deque to track max charge time in the window

        for (int i = 0; i < chargeTimes.size(); i++) {
            sum += runningCosts[i];               // Add the current running cost to the sum

            // Maintain the deque to keep track of the maximum charge time
            while (!dq.empty() && chargeTimes[dq.back()] < chargeTimes[i]) {
                dq.pop_back();
            }
            dq.push_back(i);                      // Push the current index into the deque

            // Calculate the total cost for the current window
            long long totalCost = sum * (i - j + 1) + chargeTimes[dq.front()];

            // Shrink the window from the left until the total cost is within the budget
            while (totalCost > budget) {
                sum -= runningCosts[j];           // Remove the running cost of the leftmost robot
                if (dq.front() == j) {            // If the leftmost robot's charge time is the max in deque
                    dq.pop_front();               // Remove it from the deque
                }
                j++;                              // Slide the window
                if (!dq.empty()) {
                    totalCost = sum * (i - j + 1) + chargeTimes[dq.front()]; // Recalculate total cost
                }
            }

            // Update the maximum number of robots
            ans = max(ans, i - j + 1);
        }
        return ans;                               // Return the result
    }
};
