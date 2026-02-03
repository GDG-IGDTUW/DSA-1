import java.util.*;
class Solution{
 public static int [] twoSum( int [] arr,int target 
 ){ 
    int[] ans=new int[2];
    HashMap<Integer,Integer> map= new HashMap<>();

    for(int i=0;i<arr.length;i++){
        int val=target-arr[i];
        if(map.containsKey(val)){
            
            ans[0]=i;
            ans[1]=map.get(val);
            return ans;

        }
        map.put(arr[i],i);
    }
    return ans;
 }
 
}
