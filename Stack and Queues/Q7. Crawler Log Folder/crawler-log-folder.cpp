#include<bits/stdc++.h>
using namespace std;

int minOperations(vector<string> logs) {
    stack<string>s;

    for(auto l : logs){
        if(l == "../"){
            if(!s.empty()){
                s.pop();
            }
        }else if( l == "./"){
        }else{
            int len = l.length();
            if(l[len-1] == '/'){
                s.push(l);
            }
        }
    }

    
    if(s.empty()){
        return 0;
    }else{
        return s.size();
    }
}

int main(){
    int n ;
    cout<< " Enter the value n : ";
    cin>>n;

    vector<string>logs(n);

    for(int i=0;i<n;i++){
        cin>>logs[i];
    }

    cout<<"answer is : "<<minOperations(logs)<<endl;
    return 0;
}