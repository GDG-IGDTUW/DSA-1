import java.util.Arrays;
class CarFleet {
    public int carFleet(int target, int[] position, int[] speed) {
        int n = position.length;
        // Step 1: Pair position and speed together and sort by position in descending order
        int[][] cars = new int[n][2];
        for (int i = 0; i < n; i++) {
            cars[i][0] = position[i];
            cars[i][1] = speed[i];
        }
        Arrays.sort(cars, (a, b) -> b[0] - a[0]);
        // Step 2: Calculate the time taken for each car to reach the target
        double[] time = new double[n];
        for (int i = 0; i < n; i++) {
            time[i] = (double) (target - cars[i][0]) / cars[i][1];
        }
        // Step 3: Count the number of fleets
        int fleets = 0;
        double lastFleetTime = 0;
        for (int i = 0; i < n; i++) {
            // If the current car's time > last fleet's time,
            // it forms a new fleet.
            if (time[i] > lastFleetTime) {
                fleets++;
                lastFleetTime = time[i]; // Update the time of the current fleet
            }
        }
        return fleets;
    }
}
