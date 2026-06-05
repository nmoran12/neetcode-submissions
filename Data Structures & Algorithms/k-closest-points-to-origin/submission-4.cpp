class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // A heap that holds a pair of <distance, coordinates>
        priority_queue<pair<int, vector<int>>> myQueue;
        // euclidean distance: x^2 + y^2

        // calculate distance for each point and put it into pair
        for (int i = 0; i < points.size(); i++){

            // In coordinates, x access the first index, y access the second index
            int x = points[i][0];
            int y = points[i][1];
            double distance = (x * x) + (y * y);

            // Push a pair of {distance, coordinates} into myQueue;
            myQueue.push({distance, points[i]});

            // As the max heap grows, if it exceeds size k, we simply pop the root, since that is biggest value
            if (myQueue.size() > k){
                myQueue.pop();
            }
        }

        vector<vector<int>> results;
        while (!myQueue.empty()){
            auto [dist, point] = myQueue.top();
            results.push_back(point);
            myQueue.pop();
        }



        return results;
    }
};
