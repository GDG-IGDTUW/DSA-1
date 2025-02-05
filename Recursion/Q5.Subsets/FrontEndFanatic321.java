class solution{
public List<List<Integer>> subSets(int arr[]){
  List<List<Integer>> list = new ArrayList<>();
  // ensures that subsets are generated in lexicographically order
  Arrays.sort(arr);
  backTrack(list, new ArrayList<>() , arr , 0);
  return list;
}

private void backTrack(List<List<Integer>>list , List<Integer>tempList , int arr[] , int start){
  list.add(new ArrayList<>(tempList));

  for(int i=0; i<arr.length; i++){
    tempList.add(arr[i]);
    backTrack(list, tempList , arr,i+1);
    tempList.remove(tempList.size()-1);
  }
}
}
