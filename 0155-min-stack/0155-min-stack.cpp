class MinStack {
public:
    stack<long long>st;
    long long mini = LLONG_MAX;
    MinStack() {
        
    }
    
    void push(int val) {

        if(st.empty()) 
        {
            st.push(val);
            mini = val; 
        }

        else
        {
            if(val > mini) st.push(val);
            else
            {
                st.push(2LL*val - mini);
                mini = val;
            }
        }    
    }
    
    void pop() {
        long long lastVal = st.top();
        st.pop();

        if(lastVal < mini)
        {
            mini = 2LL*mini - lastVal;
        }
    }
    
    int top() {
        long long lastVal = st.top();

        if(lastVal < mini) return mini;
        return lastVal;
    }
    
    int getMin() 
    {
        return mini;}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */