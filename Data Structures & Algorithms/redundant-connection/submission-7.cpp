class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    // Finds the parent of the current node's group
    // e.g. if we have 1 -> 2 -> 3, and we are looking at 3, it will find the '1'
    int find(int node){
        // This is 'Path Compression', essentially making all nodes in a tree directly point to the root parent.
        if (parent[node] != node){ // Checks if our current node is the parent of itself, if its not, keeping searching for parent
            parent[node] = find(parent[node]); // Find the root, then update current node to point directly to that root.
        }

        // Return the root parent
        return parent[node];
    }


    bool unite(int a, int b){
        // Get the parent of both Node A and Node B
        int rootA = find(a);
        int rootB = find(b);

        // If they have the same parent, they are in the same connected component
        // Connecting the two would make a cycle, so we just return false because we cannot connect them.
        if (rootA == rootB){
            return false;
        }

        // rank[rootA] is the height of root A.
        if (rank[rootA] > rank[rootB]){
            parent[rootB] = rootA; // Attach Root B under Root A.
        } else if (rank[rootB] > rank[rootA]){
            parent[rootA] = rootB;
        } else {
            // When both trees are same height, just attach Root B under Root A
            parent[rootB] = rootA;
            rank[rootA]++; // When merging two equal trees, the final merged tree becomes one height taller, so we must increment its height.
        }

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        rank.resize(n + 1, 0);
        parent.resize(n + 1);

        for (int i = 1; i <= n; i++){
            parent[i] = i;
        }

        for (int i = 0; i < n; i++){
            int a = edges[i][0]; // In edge = [1, 2], this gets 1
            int b = edges[i][1]; // In edge = [1, 2], this gets 2

            // Try to connect a and b, if they can't, then they were already connected, so we have formed a cycle, so return the edge
            if (unite(a, b) == false){
                return {a, b};
            }
        }

        return {};
        
    }
};
