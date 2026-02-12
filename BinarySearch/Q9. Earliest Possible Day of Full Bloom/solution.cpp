class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>>plants;
        for(int i=0;i<plantTime.size();i++){
            plants.push_back({growTime[i],plantTime[i]});
        }

        sort(plants.rbegin(), plants.rend());

        int maxbloom=0;
        int pl=0;

        for(auto& p:plants){
            pl+=p.second;
            maxbloom=max(maxbloom,pl+p.first);
        }
        return maxbloom;
        
    }
};



