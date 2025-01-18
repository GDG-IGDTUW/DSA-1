package Snowscript;
import java.util.Scanner;

public class Arrays8 {
	public static void main(String[]args) {
		Scanner s=new Scanner(System.in);
		System.out.println("Enter number of operations: ");
		int numOfoper=s.nextInt(); // taking user input for number of operations to perform
		String arr[]=new String[numOfoper]; // creating an array of size numOfoper
		for(int i=0;i<arr.length;i++) {  // creating array of operations
			System.out.println("Enter operation as either of the four : X++ / ++X / X-- / --X");
			arr[i]=s.next();
			if (!arr[i].equals("X--") && !arr[i].equals("--X") && !arr[i].equals("++X") && !arr[i].equals("X++")) {
                System.out.println("Invalid input move");
                i--;    // Decrease the index to repeat the input for this position
            }
		}
		System.out.println("The final value is : "+value(arr)); // print final answer
	}
	
	public static int value(String arr[]) {
		int ans=0;    // intial value of ans=0
		for(int i=0;i<arr.length;i++) {   // iterate through operations array
			String s=arr[i];
			if(s.equals("++X") || s.equals("X++")) {      // +1 to answer if X++ or ++X
				ans=ans+1;
			}
			else {    // if not + then -1
				ans=ans-1;
			}
		}
		return ans;
	}
}
