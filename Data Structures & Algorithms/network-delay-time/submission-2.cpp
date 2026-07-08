class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Weighted Adjacency Graph, like 2 -> {1, 1}, {3, 1}.
        // pair<int, int> = {neighbour, graph}
        unordered_map<int, vector<pair<int, int>>> graph;

        int result = 0;

        vector<int> distance(n + 1, INT_MAX);
        // Our starting point distance is always 0
        distance[k] = 0;

        // Min heap, stores: {currentDistance, node}
        // This always gives you the node with the smallest current distance as the top of the min heap.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // Build the graph
        for (vector<int>& edge : times) {
            int source = edge[0];
            int target = edge[1];
            int weight = edge[2];

            graph[source].push_back({target, weight});
        }

        minHeap.push({0, k});

        while (!minHeap.empty()){
            auto [currDist, node] = minHeap.top();
            minHeap.pop();

            // If we already found a better way to reach this node, ignore this old heap entry
            if (currDist > distance[node]){
                continue;
            }

            // 'Relax Neighbours': From the current node, try visiting each neighbour
            for (auto [neighbour, weight] : graph[node]){
                // If 1 -> 4, weight 4, then currDist = 0, weight = 4, so newDist = 4
                int newDist = currDist + weight;

                // Update: If this path reaches the neighbour faster than any previous path, update it.
                if (newDist < distance[neighbour]){
                    distance[neighbour] = newDist;
                    minHeap.push({newDist, neighbour});
                }
            }
        }

        for (int i = 1; i <= n; i++){
            if (distance[i] == INT_MAX){
                return -1;
            }

            // We do max because we want to know how long to traverse ALL nodes, which will be the maximum time taken to reach the last node.
            result = max(result, distance[i]);
        }
        
        return result;
    }
};
