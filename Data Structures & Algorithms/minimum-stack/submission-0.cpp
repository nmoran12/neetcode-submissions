class MinStack {
public:

    // Pair: {value, min_value_so_far}
    stack<pair<int, int>> myStack;

    MinStack() {}
    
    void push(int val) {
        if (myStack.empty()){
            myStack.push({val, val});
        } else {
            int currentMin = min(val, myStack.top().second);
            myStack.push({val, currentMin});
        }
    }
    
    void pop() {
        myStack.pop();
    }
    
    int top() {
        return myStack.top().first;
    }
    
    int getMin() {
        return myStack.top().second;
    }
};
