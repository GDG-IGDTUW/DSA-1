import java.util.Scanner;

public class Solution {
    public static boolean rotateString(String str, String goal){
        return((str.length() == goal.length()) && ((str + str).contains(goal)));
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter the string: ");
        String str = scn.next();

        System.out.print("Enter goal string: ");
        String goal = scn.next();

        System.out.println("Is string 'goal' the rotation of string 'str'? " + rotateString(str, goal));

        scn.close();
    }
}
