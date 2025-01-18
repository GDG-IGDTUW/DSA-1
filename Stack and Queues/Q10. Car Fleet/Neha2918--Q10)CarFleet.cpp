class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 1) return 1; // If there's only one car, it's a single fleet.

        // Pair each car's position with its time to reach the target.
        vector<pair<int, double>> cars(n);
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars[i] = {position[i], time};
        }

        // Sort cars by their starting position in descending order.
        sort(cars.rbegin(), cars.rend());

        // Use a stack to track fleets.
        stack<double> fleetStack;

        for (const auto& car : cars) {
            double currentTime = car.second;

            // If the stack is empty or the current car takes more time than the top of the stack,
            // it forms a new fleet.
            if (fleetStack.empty() || currentTime > fleetStack.top()) {
                fleetStack.push(currentTime);
            }
        }

        // The number of fleets is the size of the stack.
        return fleetStack.size();
    }
};
