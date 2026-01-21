class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int boats=0,wt=0;
        int l=0, r=people.size()-1;
        while(l<=r){
            if(people[l]+people[r]<=limit){
                boats++;
                l++,r--;
            }
            else if(people[l]==limit){
                boats++;
                l++;
            }
            else{
                boats++;
                r--;
            }
        }
        return boats;
        
    }
};
