class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // count frequency of each task
        unordered_map<char,int> freq;
        for(char t : tasks) freq[t]++;

        // max heap based on frequency
        priority_queue<int> pq;
        for(auto it : freq)
            pq.push(it.second);

        int time = 0;

        while(!pq.empty()) {
            int cycle = n + 1;
            vector<int> temp;

            // process one cycle
            while(cycle-- && !pq.empty()) {
                int cnt = pq.top(); pq.pop();
                cnt--;
                if(cnt > 0) temp.push_back(cnt);
                time++;
            }

            // push remaining tasks back
            for(int c : temp) pq.push(c);

            // add idle time if needed
            if(!pq.empty())
                time += cycle + 1;
        }

        return time;
    }
};
