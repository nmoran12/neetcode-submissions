class Solution {
public:

    vector<int> parent;

    // Finds the parent of the current node's group
    // e.g. if we have 1 -> 2 -> 3, and we are looking at 3, it will find the '1'
    int find(int node){
        while(parent[node] != node){ // While current node is not its own parent
        // A node is its own parent when its at the top of a tree, i.e. in 1 -> 2 -> 3, '1' parent would be itself, because its the root.
            node = parent[node]; // Keeping moving upwards until you reach the root
        }

        return node;
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

        parent[rootB] = rootA; // This merges root B into root A, so now rootA is the leader of the combined group.
        // Say Root B is 3, Root A is 1, so parent[1] = 1, parent[3] = 3, doing parent[rootB] = rootA is doing parent[3] = 1, so we have set
        // parent[3] (i.e. the parent of root B) to now be connected to parent of root A.
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

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
