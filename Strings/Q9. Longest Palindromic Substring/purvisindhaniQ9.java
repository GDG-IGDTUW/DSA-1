class Solution {
    int expandWithCentre(String s , int left ,int right){
        while(left>=0 && right<s.length() && s.charAt(left)==s.charAt(right)){
            left--;
            right++;
        }
    return right-left-1;

    }
    public String longestPalindrome(String s) {
        // base condition if the string is null or have no character
        if(s==null || s.length()==0) return "";
        // if length ==1
        if(s.length()==1) return s ;
        int start=0;
        int end=0;
        for(int i=0;i<s.length();i++){
            int len1=expandWithCentre(s,i,i);//even length
            int len2=expandWithCentre(s ,i,i+1);// odd length
            int max=Math.max(len1,len2);
            if(max>end-start){
                start=i-(max-1)/2;
                end=i+max/2;
            }
            
        }
    return s.substring(start,end+1);    
    }
}