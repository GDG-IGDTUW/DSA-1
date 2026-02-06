class Solution {
    public int numRescueBoats(int[] people, int limit) {
    // sort the weights
        Arrays.sort(people);
        int n=people.length;

        int i=0, j=n-1;
        int boat=0;

        while(i<j){
            // atmost 2 people in 1 boat
            if(people[i]+people[j]<=limit){
                i++;
                j--;
            }

            else if(people[j]<=limit){
                j--;
            }
            else i++;

            // incrementing boat with atmost 2 people
            boat++;
        }

        // if last 1 person is left
        if(i==j) boat++;

        return boat;
    }
}