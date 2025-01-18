class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> result;
        unordered_map<int, vector<int>> groupMap; // Map to store group size as key and indices as values

        for (int i = 0; i < n; i++) {
            int groupSize = groupSizes[i];
            groupMap[groupSize].push_back(i); // Add the person to the corresponding group size

            // If the group size matches the required number, push it to the result and reset the group
            if (groupMap[groupSize].size() == groupSize) {
                result.push_back(groupMap[groupSize]); // Add the completed group to the result
                groupMap[groupSize].clear(); // Clear the group for future use
            }
        }
        return result;
    }
};
