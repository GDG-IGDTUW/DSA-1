import java.util.*;

/*
PROBLEM STATEMENT : 

You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters
from s and removing them, causing the left and the right side of the deleted substring to concatenate together.
We repeatedly make k duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

*/

public class rashmibarodiyaQ4RemoveAllAdjacentDuplicatesInStringII {

    // Function to remove adjacent duplicates of length 'k' from the string.
    public static String removeDuplicates(String s, int k) {
        // Stack to store characters of the string
        Stack<Character> charSt = new Stack<>();
        // Stack to store the count of consecutive occurrences of each character
        Stack<Integer> countSt = new Stack<>();

        // Loop through each character in the string
        for (char ch : s.toCharArray()) {
            // If the stack is not empty and the top of the stack is the same character, increment the count
            if (!charSt.isEmpty() && charSt.peek() == ch) {
                countSt.push(countSt.peek() + 1);
            } else {
                // Otherwise, this is a new character, so initialize its count to 1
                countSt.push(1);
            }

            // Push the character onto the stack
            charSt.push(ch);

            // If the count of the current character reaches 'k', we remove the 'k' adjacent characters
            if (countSt.peek() == k) {
                // Pop the 'k' characters and their counts from the stacks
                for (int i = 0; i < k; i++) {
                    charSt.pop();
                    countSt.pop();
                }
            }
        }

        // StringBuilder to build the final string without the adjacent duplicates
        StringBuilder sb = new StringBuilder();

        // Pop all remaining characters from the stack and append to the StringBuilder
        while (!charSt.isEmpty()) {
            sb.append(charSt.pop());
        }

        // Reverse the StringBuilder to get the correct order of characters and return as a string
        return sb.reverse().toString();
    }

    public static void main(String[] args) {

        // Example Test Cases
        // Test case 1: String "abcd", with k=2, no adjacent duplicates so output should be "abcd"
        System.out.println("Output for s = \"abcd\", k = 2: " + removeDuplicates("abcd", 2));

        // Test case 2: String "deeedbbcccbdaa", with k=3, removes 'eee', 'bbb', 'ccc' then returns "aa"
        System.out.println("Output for s = \"deeedbbcccbdaa\", k = 3: " + removeDuplicates("deeedbbcccbdaa", 3));

        // Test case 3: String "pbbcggttciiippooaais", with k=2, removes 'bb', 'cc', 'gg', 'ii', 'pp', 'oo', then returns "ps"
        System.out.println("Output for s = \"pbbcggttciiippooaais\", k = 2: " + removeDuplicates("pbbcggttciiippooaais", 2));
    }
}



/*
COMPLEXITY
Time:O(n) and Space:O(n)
*/