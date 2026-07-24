class Solution {
public:

    bool dfs(int node, vector<vector<int>>& graph, vector<bool>& visited){

        // Mark as visited
        visited[node] = true;


        // Explore
        for (int neighbour : graph[node]){
            if (!visited[neighbor]){
                dfs(neighbor, graph, visited);
            }
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1){
            return false;
        }


        unordered_map<int, int> hashMap;

        int rows = edges.size();
        int cols = edges[0].size();

        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);

        // Take edges and populate adjacency list
        // We do push a -> b, and push b -> a because its an undirected graph, so [a, b] are both neighbours of each other.
        for (auto edge : edges){
            int a = edge[0];
            int b = edge[1];


            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        dfs(0, graph, visited);

        // Checks whether every node was reached by DFS
        // If any nodes are 'false' (i.e. not reached) then our tree size is not = n, so return false.
        for (int i = 0; i < visited.size(); i++){
            if (visited[i] == false){
                return false;
            }
        }


        return true.
    }
};
