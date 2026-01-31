class Solution {
    public String destCity(List<List<String>> paths) {
        Map<String, Integer> outdegree = new HashMap<>();
        for(List<String> path : paths){
            String from = path.get(0);
            String to = path.get(1);
            outdegree.put(to, outdegree.getOrDefault(to, 0)+0);
            outdegree.put(from, outdegree.getOrDefault(from, 0)+1);
        }
        for(Map.Entry<String, Integer> e : outdegree.entrySet()){
            String city = e.getKey();
            int degree = e.getValue();
            if(degree == 0)
                return city;
        }
        return "";
    }
}
