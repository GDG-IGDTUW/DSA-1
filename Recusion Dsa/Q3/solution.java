class Solution {
    static final long MOD = 1000000007;

    public int countGoodNumbers(long n) {
        long evenPositions = (n + 1) / 2; // indices 0,2,4,etc
        long oddPositions = n / 2;        // indices 1,3,5,etc

        long evenWays = modPow(5, evenPositions);
        long oddWays = modPow(4, oddPositions);

        return (int)((evenWays * oddWays) % MOD);
    }

    private long modPow(long base, long exp) {
        long result = 1;
        base %= MOD;

        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }
}
