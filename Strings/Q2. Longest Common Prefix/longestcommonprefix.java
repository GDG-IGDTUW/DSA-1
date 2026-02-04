class Solution {
    public String longestCommonPrefix(String[] strs) {
        Arrays.sort(strs);
        String first=strs[0];
        String last=strs[strs.length-1];
        StringBuilder st=new StringBuilder();
        
        for(int i =0 ;i<Math.min(first.length(),last.length());i++){
            char ch1=first.charAt(i);
            char ch2=last.charAt(i);
            if(ch1==ch2) st.append(ch1);
            else if(ch1!=ch2) break;
            
        }
    return st.toString();
    }
}