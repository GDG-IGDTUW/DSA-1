import java.util.*;

class Solution {
    public int earliestFullBloom(int[] plantTime, int[] growTime) {

        int n = plantTime.length;
        int[][] seeds = new int[n][2];

        // Combine plant and grow times
        for (int i = 0; i < n; i++) {
            seeds[i][0] = plantTime[i];
            seeds[i][1] = growTime[i];
        }

        // Sort by growTime DESC
        Arrays.sort(seeds, (a, b) -> b[1] - a[1]);

        int currentPlantDay = 0;
        int answer = 0;

        for (int[] seed : seeds) {
            currentPlantDay += seed[0];
            answer = Math.max(answer, currentPlantDay + seed[1]);
        }

        return answer;
    }
}
