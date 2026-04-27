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

    int balancedHelper(TreeNode* root){
        if (!root){
            return 0;
        }

        int leftHeight = balancedHelper(root->left);
        int rightHeight = balancedHelper(root->right);

        if (leftHeight - rightHeight > 1 || rightHeight - leftHeight > 1){
            return -1;
        }
        return max(leftHeight, rightHeight) + 1;
    }



    bool isBalanced(TreeNode* root) {
        return balancedHelper(root) >= 0;


    }
};
