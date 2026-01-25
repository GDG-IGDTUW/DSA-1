class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        stack<int> st;
        vector<int> res;
        
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            
            if(st.empty()){
                res.push_back(-1);
                st.push(arr[i]);
            }else if(st.top()<arr[i]){
                res.push_back(st.top());
                st.push(arr[i]);
            }
        }
        
        return res;
        
    }
};



