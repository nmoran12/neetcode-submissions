class MinStack {
public:

    // Pair: {value, min_value_so_far}
    stack<pair<int, int>> myStack;

    MinStack() {}
    
    // Push checks if the new value coming in is smaller than the smallest number already in the stack
    void push(int val) {
        // Case 1: Stack is empty
        // Therefore, there are no previous values to compare to, so the new value is automatically the smallest item in the stack.
        if (myStack.empty()){
            myStack.push({val, val});
        // Case 2: Stack already has items
        // Look at top item's tag (myStack.top().second) to see what the stack's minimum currently is.
        // Compare new val to that existing minimum
        // Push the new value, and new calculated minimum
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
