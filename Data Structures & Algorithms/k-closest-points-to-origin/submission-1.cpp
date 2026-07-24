class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;
        vector<vector<int>> results;

        // 2D Distance: sqrt((x2-x1)^2 + (y2-y1)^2)
        double x2 = 0;
        double y2 = 0;


            for (int j = 0; j < points.size(); j++){
                double x1 = points[j][0];
                double y1 = points[j][1];

                double dist2D = (x1 * x1) + (y1 * y2);

                maxHeap.push({dist2D, points[j]});

                if (maxHeap.size() > k){
                    maxHeap.pop();
                }

            }

            while (!maxHeap.empty()){
                results.push_back(maxHeap.top().second);
                maxHeap.pop();
            }
        
        return results;
    }
};
