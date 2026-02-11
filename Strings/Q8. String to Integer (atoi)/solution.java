class Solution {
    public int myAtoi(String s) {
      int i =0;
        while(i<s.length() && s.charAt(i)==' ')i++;
        
        int sign=1;
        long nums=0;
        if(i<s.length() && (s.charAt(i)=='+' || s.charAt(i)=='-')){
            sign=(s.charAt(i)=='-') ? -1:1;
            i++;
        }


        while(i<s.length() && Character.isDigit(s.charAt(i))){
            nums=nums*10+(s.charAt(i)-'0');

            if(nums*sign>=Integer.MAX_VALUE) return Integer.MAX_VALUE;
            if(nums*sign<=Integer.MIN_VALUE) return Integer.MIN_VALUE ;
            i++;
        }
        
    return (int)nums*sign;  
    } 
}