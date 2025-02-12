class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, ArrayList<String>> anagrams = new HashMap<>();
        for(String s : strs){
            char c[] = s.toCharArray();
            Arrays.sort(c);
            String key = String.valueOf(c);
            if(!anagrams.containsKey(key)){
                anagrams.put(key , new ArrayList<>());
            }
            anagrams.get(key).add(s);
        }
        return new ArrayList(anagrams.values());
    }
}
