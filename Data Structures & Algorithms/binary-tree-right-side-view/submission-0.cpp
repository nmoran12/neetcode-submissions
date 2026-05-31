/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // It needs to be a TreeNode*, not int, so you can access children.
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        int queueSize = 0;
        vector<int> rightView;
        
        if (!root) return rightView;


        while (!myQueue.empty()){
            queueSize = myQueue.size();

            for (int i = 0; i < queueSize; i++){
                // We need a local variable that points to the front of the queue, e.g. the current node we are on
                // We need this curr node because 'root' ALWAYS points to the actual root of the tree, so we can't use root,
                // we must make a new variable that points to the current node we are at.
                TreeNode* curr = myQueue.front();

                myQueue.pop();


                if (i == (queueSize - 1)){
                    rightView.push_back(curr->val);
                }

                if (curr->left != nullptr) myQueue.push(curr->left);
                if (curr->right != nullptr) myQueue.push(curr->right);

            }

        }

        return rightView;
    }
};
