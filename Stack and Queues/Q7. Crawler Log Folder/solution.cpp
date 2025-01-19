int minOperations(vector<string>& logs) {
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
