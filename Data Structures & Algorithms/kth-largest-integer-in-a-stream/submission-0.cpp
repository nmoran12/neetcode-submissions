class KthLargest {
public:

        vector<int> heap;
        int kVal;


    KthLargest(int k, vector<int>& nums) {
        heap.push_back(0);
        kVal = k;

        for (int i = 0; i < nums.size(); i++){
            add(nums[i]);
        }
    }

    
    // Push Operation
    int add(int val) {

        heap.push_back(val);
        int i = heap.size() - 1;

        while (i > 1 && heap[i] < heap[(i / 2)] ){
            int temp = heap[(i / 2)];
            heap[(i / 2)] = heap[i];
            heap[i] = temp;

            i = i / 2;
            

        }

        if (heap.size() > kVal + 1) {
            heap[1] = heap.back();
            heap.pop_back();
            
            int curr = 1; 

            while (curr * 2 < heap.size()) {
                int leftChild = curr * 2;
                int rightChild = curr * 2 + 1;
                int smallest = leftChild;

                if (rightChild < heap.size() && heap[rightChild] < heap[leftChild]) {
                    smallest = rightChild;
                }

                if (heap[curr] <= heap[smallest]) {
                    break; 
                }

                int temp = heap[curr];
                heap[curr] = heap[smallest];
                heap[smallest] = temp;
                
                curr = smallest; 
            }
        }

        return heap[1];
    }
};
