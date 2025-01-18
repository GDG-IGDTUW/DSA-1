class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> result(n);

        // Max heap to store {score, index}
        priority_queue<pair<int, int>> maxHeap;

        // Push all scores with their indices into the heap
        for (int i = 0; i < n; i++) {
            maxHeap.push({score[i], i});
        }

        // Assign ranks based on the order they are popped from the heap
        int rank = 1;
        while (!maxHeap.empty()) {
            int index = maxHeap.top().second; // Get the index of the current score
            maxHeap.pop();

            if (rank == 1) {
                result[index] = "Gold Medal";
            } else if (rank == 2) {
                result[index] = "Silver Medal";
            } else if (rank == 3) {
                result[index] = "Bronze Medal";
            } else {
                result[index] = to_string(rank);
            }

            rank++;
        }

        return result;
    }
};
