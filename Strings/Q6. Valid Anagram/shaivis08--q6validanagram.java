lass Solution {
    public boolean isAnagram(String s, String t) {
        //converting to character array
        char[] s_array = s.toCharArray();
        char[] t_array = t.toCharArray();

        //sorting character arrays
        Arrays.sort(s_array);
        Arrays.sort(t_array);

        //checking if sorted version are equal or not

        String sorted_s = new String(s_array);
        String sorted_t = new String(t_array);

        return sorted_s.equals(sorted_t);
        
    }
}
