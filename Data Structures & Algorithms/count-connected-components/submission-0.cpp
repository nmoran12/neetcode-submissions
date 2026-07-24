class Solution {
public:

    void dfs(int node, vector<vector<int>>& adjacencyList, vector<bool>& visited(n, false)){
        // base case: if node is visited, just return
        if (visited[node]){
            return;
        }


        // Mark as visited
        visited[node] = true;


        // Process it
        for (int neighbours : adjacencyList[node]){ // Look at every node connected to my current node
            dfs(neighbour, adjacencyList, visited); // Go explore that neighbour
        }


    }

    int countComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adjacencyList(n);
        vector<bool> visited(n, false);
        int componentCount = 0;
        
        // Populate the undirected graph adjacency list
        for (auto edge : edges){

            int a = edge[0];
            int b = edge[1];

            adjacencyList[a].push_back(b);
            adjacencyList[b].push_back(a);
        }

        for (int i = 0; i < n; i++){

                if (!visited[i]){
                    componentCount++;
                    dfs(i, adjacencyList, visited);
                }
        }

        return componentCount;
    }
};
