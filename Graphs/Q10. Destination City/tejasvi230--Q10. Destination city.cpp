class Solution {
public:
    string destCity(vector<vector<string>>& paths) {

        unordered_set<string> from;

        // store all starting cities
        for (auto &p : paths)
            from.insert(p[0]);

        // city that never appears as start is destination
        for (auto &p : paths) {
            if (from.find(p[1]) == from.end())
                return p[1];
        }

        return "";
    }
};
