class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<long long> myStack;

        for (long long i = 0; i < tokens.size(); i++){

            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                long long rightNum = myStack.top();
                myStack.pop();

                long long leftNum = myStack.top();
                myStack.pop();

                if (tokens[i] == "+"){
                    myStack.push(leftNum + rightNum);
                } else if (tokens[i] == "-"){
                    myStack.push(leftNum - rightNum);
                } else if (tokens[i] == "*"){
                    myStack.push(leftNum * rightNum);
                } else if (tokens[i] == "/"){
                    myStack.push(leftNum / rightNum);
                }
            } else {
                myStack.push(stoll(tokens[i]));
            }
        }
        return myStack.top();
    }
};
