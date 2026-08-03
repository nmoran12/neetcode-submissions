class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int maxArea = 0;

        // Stack stores pairs of {start_index, height}
        stack<pair<int, int>> myStack;
        
        for (int i = 0; i < heights.size(); i++){
            int start = i;

            // When a drop in height occurs, pop taller bars and compute their max area
            while (!myStack.empty() && myStack.top().second > heights[i]){
                auto [index, height] = myStack.top();
                myStack.pop();

                // Compute area bounded on the right by current index 'i'
                // Index = the left boundary (the furthest left position this height was able to reach)
                // i = the right boundary (the current index whose shorter bar forced us to stop and pop)
                maxArea = max(maxArea, height * (i - index));

                // Backward extension: So current shorter bar can start where the popped taller bar originally started!
                start = index;
            }

            // Push current height with its backward-extended start index
            myStack.push({start, heights[i]});
        }

        // Cleanup: Remaining elements in the stack extend all the way to the end of the histogram
        int n = heights.size();
        while (!myStack.empty()){
            auto [index, height] = myStack.top();
            myStack.pop();

            maxArea = max(maxArea, height * (n - index));
        }

        return maxArea;
    }
};
