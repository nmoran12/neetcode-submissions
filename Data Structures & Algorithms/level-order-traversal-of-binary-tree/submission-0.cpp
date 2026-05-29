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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> subset;

        if (!root) {
            return subset;
        }

        queue<TreeNode*> myQueue;
        myQueue.push(root);

        while (!myQueue.empty()) {
            int queueSize = myQueue.size();
            vector<int> currentLevel;

            for (int j = 0; j < queueSize; j++) {
                TreeNode* currentNode = myQueue.front();
                myQueue.pop();

                currentLevel.push_back(currentNode->val);

                if (currentNode->left) {
                    myQueue.push(currentNode->left);
                }

                if (currentNode->right) {
                    myQueue.push(currentNode->right);
                }
            }

            subset.push_back(currentLevel);
        }

        return subset;
    }
};