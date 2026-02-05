class Solution {
    public int myAtoi(String s) {

        int i = 0, n = s.length();
        int sign = 1;
        long num = 0;

        // 1️⃣ Skip leading whitespaces
        while (i < n && s.charAt(i) == ' ') {
            i++;
        }

        // 2️⃣ Handle sign
        if (i < n && (s.charAt(i) == '+' || s.charAt(i) == '-')) {
            sign = (s.charAt(i) == '-') ? -1 : 1;
            i++;
        }

        // 3️⃣ Convert digits
        while (i < n && Character.isDigit(s.charAt(i))) {
            num = num * 10 + (s.charAt(i) - '0');

            // 4️⃣ Clamp on overflow
            if (sign * num >= Integer.MAX_VALUE) {
                return Integer.MAX_VALUE;
            }
            if (sign * num <= Integer.MIN_VALUE) {
                return Integer.MIN_VALUE;
            }

            i++;
        }

        return (int) (sign * num);
    }
}
