class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        for (int c : s){
            if (c == '(' || c == '[' || c == '{'){
                myStack.push(c);
            } else if (c == ')' && !myStack.empty() && myStack.top() == '('){
                myStack.pop();
            } else if (c == ']' && !myStack.empty() && myStack.top() == '['){
                myStack.pop();
            } else if (c == '}' && !myStack.empty() && myStack.top() == '{'){
                myStack.pop();
            }

            return true;
        }

        return false;
    }
};
