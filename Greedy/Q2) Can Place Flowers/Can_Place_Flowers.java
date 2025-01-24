public class solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int count = 0; // keeping track of the number of flowers placed
        for (int i = 0; i < flowerbed.length; i++) {   // // Iterating through each space in the flowerbed
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.length - 1 || flowerbed[i + 1] == 0)) {   //// Checking if the current space is empty and its neighbors are also empty
                flowerbed[i] = 1; // Placing a flower in the current space
                count++;   // // Incrementing the count of flowers placed
            }
            if (count >= n) {     // If we've placed n flowers, we can stop and return true
                return true;
            }
        }
        // If we've iterated through the entire flowerbed and haven't placed n flowers, return false
        return false;
    }
    public static void main(String[] args) {
        solution Solution = new solution();
        int[] flowerbed = {1, 0, 0, 0, 1};
        int n = 1;
        boolean result = Solution.canPlaceFlowers(flowerbed, n);
        System.out.println("Can place " + n + " flowers: " + result);

        flowerbed = new int[]{1, 0, 0, 0, 1};
        n = 2;
        result = Solution.canPlaceFlowers(flowerbed, n);
        System.out.println("Can place " + n + " flowers: " + result);
    }
}
