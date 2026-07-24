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

        unordered_map<Node*, Node*> hashMap;

    Node* dfs(Node* node, unordered_map<int, int> hashMap){

        // Base Cases:

        // If old node has already been cloned, just return the new node
        if (hashMap.count(node)){
            return hashMap[node];
        }

        // Make copy of old node
        Node* copy = new Node(node->val);

        // Assign it to old node in hash map, so now old node : new node together
        hashMap[node] = copy;

        // For every old neighbor of the original node, get that neighbour's clone, and attach it to my cloned nodes neighbour list
        for (Node* oldNeighbor : node->neighbors){
            copy->neighbors.push_back(dfs(node)); // Take my cloned node called copy, and add the cloned version of this neighbour to its neighbours list.
        }
        // dfs(node) returns the cloned version of that node, so whenever you read 'dfs(some node)' its just returning the cloned version of that node.



        return copy;
    }

    Node* cloneGraph(Node* node) {
        if (node == nullptr){
            return nullptr;
        }


        return dfs(node);
    }
};