import java.util.ArrayList;

public class AvwalKaur__Q2_Combination_Sum {
    static void f(int idx, int target, int[] candidates, ArrayList<Integer> ll, ArrayList<ArrayList<Integer>> ans) {
        // Base Case
        if(idx==candidates.length) {
            if(target==0) {
                ans.add(new ArrayList<>(ll));
            }
            return;
        }
        // If the element arr[idx] is picked
        if(candidates[idx]<=target) {
            ll.add(candidates[idx]);
            f(idx, target-candidates[idx], candidates, ll, ans);
            ll.remove(ll.size()-1);
        }
        // If the element arr[idx] is not picked
        f(idx+1, target, candidates, ll, ans);
    }
    public static void main(String[] args) {
        int[] candidates = {2,3,6,7};
        int target = 7;
        ArrayList<ArrayList<Integer>> ans=new ArrayList<>();
        f(0, target,candidates, new ArrayList<>(),ans);
        System.out.println("All possible combinations that sum to target are: "+ans);
    }
}
