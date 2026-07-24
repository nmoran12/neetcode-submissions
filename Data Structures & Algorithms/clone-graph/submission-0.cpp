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

        // Maps old node : new node.
        // Helps prevent duplicates
        unordered_map<Node*, Node*> oldToNew;

    // Helper dfs should take the old node, and return the new cloned version of that node
    // E.g. take in Old Node 2 -> return New Node 2
    node* dfs(Node* node){

        // If old node has already been cloned (i.e. a new node exists) then just return the new node.
        if (oldToNew.count(node)){
            return oldToNew[node];
        }

        // If we haven't created its new clone node yet, create it
        // NOTE: At this point, we have created the new cloned node, but it has no neighbours yet
        Node* copy = new Node(node->val);

        // Before we add its neighbours, we must add it to the hash map.
        // Now we have Old Node 1 -> New Node 1
        oldToNew[node] = copy;

        // We now must add its neighbours, so we must clone its neighbours.
        // This is:
        // For every old neighbour:
        //      get me that neighbour's cloned version
        //      attach it to my cloned node
        for (Node* newNode : node->neighbors){
            copy->neighbors.push_back(dfs(newNode));
        }


        // Return the cloned node
        return copy;
    }

    Node* cloneGraph(Node* node) {
        // Handle empty graphs, if we get one just return straight away
        if (node == nullptr){
            return nullptr;
        }

        return dfs(node);
    }
};
