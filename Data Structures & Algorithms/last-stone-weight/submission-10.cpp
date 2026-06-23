class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Declare max heap
        priority_queue<int> myHeap;

        // Push stones into max heap
        for (int nums : stones){
            myHeap.push(nums);
        }

        // Two heaviest stones is root + left child
        while (myHeap.size() > 1){
                int first = myHeap.top();
                myHeap.pop();
                int second = myHeap.top();
                myHeap.pop();
                if (second < first){
                    myHeap.push(first - second);
                };
        }

        myHeap.push(0);
        return myHeap.top();
        
    }
};
