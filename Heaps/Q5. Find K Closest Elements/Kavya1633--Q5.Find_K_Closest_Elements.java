class Solution {
    class Pair{
        int diff;
        int ele;

        Pair(int diff,int ele){
            this.diff=diff;
            this.ele=ele;
        }
    }
    public List<Integer> findClosestElements(int[] arr, int k, int x) {

        // MaxHeap
        PriorityQueue<Pair> queue=new PriorityQueue<>(
                (a,b)->{
                    if(a.diff!=b.diff) return b.diff-a.diff;
                    return b.ele-a.ele;
                }
        );

        for(int ele:arr){
            int diff=Math.abs(ele-x);
            queue.add(new Pair(diff,ele));

            // get K closest ele (removing max-diff ele)
            while(queue.size()>k){
                queue.remove();
            }

        }

        List<Integer> closestEle=new ArrayList<>();

        // add the ele to the list
        while(!queue.isEmpty()){
            closestEle.add(0,queue.peek().ele);
            queue.remove();
        }
        // sort the list
        Collections.sort(closestEle);

        return closestEle;


    }
}