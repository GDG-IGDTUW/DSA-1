class MinStack {
    private:
        stack<int> st;
        stack<int> minSt;
    
    public:
        MinStack() {
            
        }
        
        void push(int val) {
            st.push(val);
            if (minSt.empty()) {
                minSt.push(val);
            } else {
                minSt.push(min(val, minSt.top()));
            }
        }
        
        void pop() {
            st.pop();
            minSt.pop();
        }
        
        int top() {
            return st.top();
        }
        
        int getMin() {
            return minSt.top();
        }
    };
    