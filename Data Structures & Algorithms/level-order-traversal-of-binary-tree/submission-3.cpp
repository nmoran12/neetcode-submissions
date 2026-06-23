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
        // Base Case 1: If tree is empty, return
        if (root == nullptr){
            return {};
        }

        // queue
        queue<TreeNode*> myQueue;
        // initialise with root of tree
        myQueue.push(root);

        vector<vector<int>> results;


        while (!myQueue.empty()){
            int counter = myQueue.size();
            vector<int> subset;


            for (int i = 0; i < counter; i++){
                TreeNode* current = myQueue.front();
                myQueue.pop();

                subset.push_back(current->val);

                if (current->left != nullptr){
                    myQueue.push(current->left);
                }

                if (current->right != nullptr){
                    myQueue.push(current->right);
                }
            }
            results.push_back(subset);
        }


        return results;
    }
};
