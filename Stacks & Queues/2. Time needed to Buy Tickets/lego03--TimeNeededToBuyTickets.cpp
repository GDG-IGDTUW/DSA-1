class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        if (n == 1)
            return tickets[0];
        int time = 0;
        for (int i = 0; i < n; i++) {
            if (i <= k)
                time += min(tickets[i], tickets[k]);
            else
                time += min(tickets[k] - 1, tickets[i]);
        }
        return time;
    }
};
