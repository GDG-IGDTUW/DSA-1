class Solution {
public:
    int maxCoins(vector<int>& piles) {
        // Get the total number of piles
        int n = piles.size();

        // Sort the piles in ascending order to maximize our pick later
        sort(begin(piles), end(piles));

        int result = 0; // To store the total coins we collect

        int Bob = 0;    // Pointer representing Bob's turn (smallest piles)
        int M = n - 2;  // Pointer to our turn (second largest pile)

        // Iterate while there are still piles for Bob
        while (M > Bob) {
            result += piles[M]; // Add the second largest pile to our total

            M -= 2; // Move to the next "second largest" pile
            Bob++;  // Move Bob's pointer to the next smallest pile
        }

        return result; // Return the total coins collected
    }
};
