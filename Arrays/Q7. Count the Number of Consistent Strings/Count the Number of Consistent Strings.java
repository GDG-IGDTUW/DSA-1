//java based solution
class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        HashMap <Character,Integer> map= new HashMap<>();
        for(int i=0;i<allowed.length();i++)
        {
            map.put(allowed.charAt(i),i);
        }
        int count=0;boolean answer=true;
        for(int i=0;i<words.length;i++)
        {
           answer=true;
           String word=words[i];
           for(int j=0;j<word.length();j++)
           {
            char c=word.charAt(j);
            if(!map.containsKey(c))
                 answer=false;
           }
           if(answer==true)
           count++;
        }
        return count;
    }
}
