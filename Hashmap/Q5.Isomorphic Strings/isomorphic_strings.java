import java.util.*;

public class isomorphic_strings {
    // Approach 1
    // Using two Hashmaps
    static boolean isIsormophicI(String s, String t) {
        if(s.length()!=t.length()) return false;

        HashMap<Character, Integer> mpp1=new HashMap<>();
        HashMap<Character, Integer> mpp2=new HashMap<>();
        for(int i=0;i<s.length();i++) {
            char sc=s.charAt(i);
            char tc=t.charAt(i);
            if(!mpp1.containsKey(sc)) mpp1.put(sc, i);
            if(!mpp2.containsKey(tc)) mpp2.put(tc, i);

            // if both characters exist previously, check if they are mapped to each other or not
            if(mpp1.get(sc)!=mpp2.get(tc)) return false;
        }
        return true;
    }

    // Approach 2
    // Using two integer arrays (without using HashMaps)
    static boolean isIsomorphicII(String s, String t) {
        if(s.length()!=t.length()) return false;

        int[] a1=new int[256];
        int[] a2=new int[256];
        for(int i=0;i<s.length();i++) {
            char sc=s.charAt(i);
            char tc=t.charAt(i);
            if(a1[sc]==0 && a2[tc]==0) {
                a1[sc]=tc;
                a2[tc]=sc;
            } else {
                if(a1[sc]!=tc || a2[tc]!=sc) return false;
            }
        }
        return true;
    }
    public static void main(String[] args) {
        // Take user input for strings s and t
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the string s: ");
        String s=sc.next();
        System.out.print("Enter the string t: ");
        String t=sc.next();
        if(isIsormophicI(s, t)==true) System.out.println(s+" and "+t+" are isomorphic");
        else System.out.println(s+" and "+t+" are not isomorphic");
    }
}
