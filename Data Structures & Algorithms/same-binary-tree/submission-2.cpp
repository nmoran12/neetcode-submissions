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

    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Check if trees are empty
        if (!p && !q) return true;

        // Check if one is empty
        if (!p || !q){
            return false;
        }

        if (p->val != q->val){
            return false;
        }

        int leftSame = isSameTree(p->left, q->left);
        int rightSame = isSameTree(p->right, q->right);

        if (leftSame && rightSame){
            return true;
        }

        return false;
    }
};
