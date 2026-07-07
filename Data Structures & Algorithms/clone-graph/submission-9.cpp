/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

        unordered_map<Node*, Node*> adjacencyList;

    Node* dfs(Node* node){
        // Base Case: If new node already exists, just return
        if (adjacencyList.count(node)){
            return adjacencyList[node];
        }


        // Create new node
        // We use 'node->val' not 'node' because 'node->val' gets the VALUE at that node, which is what we are cloning. 'node' just gets the memory address.
        Node* copy = new Node(node->val);

        adjacencyList[node] = copy;

        // For all old nodes, get their neighbours and add it to the new node neighbour's.
        for (Node* oldNodeNeighbours : node->neighbors){
            Node* clonedNeighbor = dfs(oldNodeNeighbours); // Clone the original neighbour
            copy->neighbors.push_back(clonedNeighbor); // Add that cloned neighbour to the current cloned node's neighbour list
        }


        return copy;
    }


    Node* cloneGraph(Node* node) {
        if (node == nullptr){
            return nullptr;
        }


        return dfs(node);
    }
};
