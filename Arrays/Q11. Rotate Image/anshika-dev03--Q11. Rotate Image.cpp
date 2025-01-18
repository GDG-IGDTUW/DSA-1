#include <bits/stdc++.h>
using namespace std;
void rotate_image( vector<vector<int>> &mat){
  int n=mat.size();
  //step 1: transpose the matrix
  //diagonal elements remain the same
  //we traverse the upper triangular elements and swap them with lower triangular elements
  for(int i= 0;i< n-1; i++){ 
    for(int j=i+1;j<n;j++){
      swap(mat[i][j],mat[j][i]);

    }
  }

  //step 2: reverse the rows
  for(vector<int> &row : mat){
    reverse(row.begin(),row.end());
  }



}
int main(){
  vector<vector<int>> example;
  example={{1,2,3},{4,5,6},{7,8,9}};
  rotate_image(example);
  cout<<"Rotated image:"<<endl;
  for(int i=0;i<example.size();i++){
    for(int j=0;j<example.size();j++){
      cout<<example[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}