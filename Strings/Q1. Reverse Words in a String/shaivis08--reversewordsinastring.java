class Solution {
    public String reverseWords(String s) {
        String result = "";
        String[] words = s.split(" "); //retrieving all words in an array
        for (int i=words.length-1;i>=0;i--) {
            words[i] = words[i].strip(); //removing any extra spaces
            if (words[i].isEmpty()) {
                continue; //skipping empty elements
            }
            else {
                result+=words[i];
                result+=" ";
            }
        }
        result = result.strip(); //removing leading and trailing spaces in final answer
        return result;
    }
}
