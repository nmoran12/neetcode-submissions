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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        int leftSide = isBalanced(root->left);
        int rightSide = isBalanced(root->right);

        if (leftSide != rightSide || (leftSide + 1) != rightSide || (leftSide - 1) != rightSide || 
        (rightSide + 1) != leftSide || (rightSide - 1) != leftSide){
            return false;
        }

        return true;
    }
};
