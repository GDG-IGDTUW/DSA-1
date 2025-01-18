//java solution using HashMap ran 100% testcases on leetcode

import java.util.HashMap;
class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        HashMap<Integer, Integer> Aa = new HashMap<>();
        HashMap<Integer, Integer> Bb = new HashMap<>();
        int C[]= new int [A.length];
        int count=0;
        for(int i=0;i<A.length;i++)
        {
         Aa.put(A[i],i);
         Bb.put(B[i],i);
         if(A[i]==B[i])
         C[i]=++count;
         else if(Aa.containsKey(B[i]))
         {
            C[i]=++count; if(Bb.containsKey(A[i]))
         {
            C[i]=++count;
         }
        }
        else  if(Bb.containsKey(A[i]))
         {
            C[i]=++count;
         }
         else 
         C[i]=count;
        }
        return C;
    }
}
