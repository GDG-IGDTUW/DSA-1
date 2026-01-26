class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //only if totalgas>=totalcost then only it is possible otherwise we skip and start from the next index
        int tank=0;
        int totalgas=0;
        int totalcost=0;
        int start=0; //the ans var that stores from where we shld start
        for(int i=0;i<gas.size();i++){
            totalgas+=gas[i];
            totalcost+=cost[i];

            tank+=gas[i]-cost[i]; //amt of gas left at a particular index

            if(tank<0){
                start=i+1;
                tank=0;
            }
        }
        return (totalgas>=totalcost?start:-1);
    }
};
