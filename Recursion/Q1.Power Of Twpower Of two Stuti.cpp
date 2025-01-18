#include<iostream>
using namespace std;
bool isPowerOf2(int n){
if(n==1)return true;
if(n%2!=0)return false;
n/=2;
return isPowerOf2(n);
}
int main(){
int n;
cin>>n;
isPowerOf2(n)?cout<<"yes":cout<<"no";
return 0;
//in the above code we check for power of 2 if it is a power of 2 then only 2 should exist as factor incase any other prime factor is 
//found that can be detected using the n%2 part that stops and return false the moment we get to know of non divisibility by 2 which is mandatory
}
