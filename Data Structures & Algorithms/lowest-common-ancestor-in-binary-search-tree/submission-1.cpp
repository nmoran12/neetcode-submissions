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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;

        // Finding split in path
        if (p->val < root->val && q->val > root->val || p->val > root->val && q->val < root->val){
            return root;
        }

        // If we reach the node itself
        if (root->val == p->val || root->val == q->val){
            return root;
        };

        // If both p and q are larger or smaller than root, go down that side
        if (p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p, q);
        }

        if (p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left, p, q);
        }



        return root;
    }
};
