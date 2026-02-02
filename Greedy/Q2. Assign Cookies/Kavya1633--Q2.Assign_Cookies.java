class Solution {
    public int findContentChildren(int[] g, int[] s) {

        // sort the s[] & g[]
        Arrays.sort(s);
        Arrays.sort(g);


        int i=0, n=s.length;
        int j=0, m=g.length;

        while(i<n && j<m){

            // if cond statisfy move to next child
            if(g[j]<=s[i]){
                j++;
            }
            i++;
        }

        return j;
    }
}