class Solution {
    public void helper(int open, int close, int n, StringBuilder sb, List<String> ans){
        if(close == n){
            ans.add(sb.toString());
            return;
        }

        if(open<n){
            sb.append('(');
            helper(open+1, close, n, sb, ans);
            sb.deleteCharAt(sb.length()-1);
        }

        if(close<open){
            sb.append(')');
            helper(open, close+1, n, sb, ans);
            sb.deleteCharAt(sb.length()-1);
        }
    }

    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        helper(0, 0, n, sb, ans);
        return ans;
    }
}
