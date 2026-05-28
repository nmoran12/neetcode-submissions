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

    bool inspector(TreeNode* a, TreeNode* b){
        // base cases:
        if (!a && !b) return true;

        // If one tree is null, or their value dont match up, return false.
        if (!a || !b || a->val != b->val) return false;


        return inspector(a->left, b->left) && inspector(a->right, b->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;

        if (!root || !subRoot) return false;

        if (inspector(root, subRoot)) return true;


        // It might be OR, not AND, because the subRoot value will only exist at one node, so we check both left and right
        // and check if it exists at one OR the other, because it literally cant be in both.
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
