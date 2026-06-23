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
    int maxDepth(TreeNode* root) {
        // Base Case 1: If root is nullptr i.e. we have reached the bottom of a tree
        if (root == nullptr){
            return 0;
        }

        int greatestDepth = 0;

        int leftSubtree = maxDepth(root->left);
        int rightSubtree = maxDepth(root->right);
        
        return max(leftSubtree, rightSubtree) + 1;
    }
};
