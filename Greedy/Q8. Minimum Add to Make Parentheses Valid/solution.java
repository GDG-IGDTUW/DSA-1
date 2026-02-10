class Solution {
    public int minAddToMakeValid(String s) {

        int open = 0;     // count of unmatched '('
        int moves = 0;    // number of insertions needed

        for (char c : s.toCharArray()) {
            if (c == '(') {
                open++;
            } else { // ')'
                if (open > 0) {
                    open--;   // match with an existing '('
                } else {
                    moves++; // need to insert '('
                }
            }
        }

        // remaining '(' need ')' insertions
        return moves + open;
    }
}
