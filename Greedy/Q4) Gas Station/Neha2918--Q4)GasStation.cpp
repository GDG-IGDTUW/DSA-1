class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int current = 0;        // Tracks the current fuel balance while traversing
        int total_fuel = 0;     // Total fuel available in all stations
        int total_cost = 0;     // Total fuel cost required to travel between all stations
        int start = 0;          // Starting index of the circuit

        // Calculate the total fuel available across all stations
        for (int i = 0; i < gas.size(); i++) {
            total_fuel += gas[i];
        }

        // Calculate the total fuel cost across all stations
        for (int i = 0; i < gas.size(); i++) {
            total_cost += cost[i];
        }

        // If total fuel is less than total cost, completing the circuit is impossible
        if (total_fuel < total_cost) {
            return -1;
        }

        // Iterate through the stations to determine the starting point
        for (int i = 0; i < gas.size(); i++) {
            // Add the current station's fuel gain/loss to the balance
            current += (gas[i] - cost[i]);

            // If the balance becomes negative, reset the starting point to the next station
            if (current < 0) {
                start = i + 1;
                current = 0; // Reset current fuel balance
            }
        }

        // Return the starting point of the circuit
        return start;
    }
};
