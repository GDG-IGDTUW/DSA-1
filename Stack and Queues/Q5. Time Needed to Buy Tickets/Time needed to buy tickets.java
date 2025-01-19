public class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int n = tickets.length;
        int count = 0;
        while(true){ //this statement will cause the for loop to run till the return condition is reached.
        for(int i = 0; i<tickets.length; i++){
            if(tickets[i]>0){
                tickets[i]--;
                count++;
            }
            if(i == k && tickets[i]==0){
                return count;
            }
        }
        }

    }
}
//Time complexity: O(n)
//Space complexity: O(1)
