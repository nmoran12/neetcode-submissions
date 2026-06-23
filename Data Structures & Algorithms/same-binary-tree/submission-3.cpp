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
        // Base Case: If both trees are empty, they match, return true
        if (p == nullptr && q == nullptr){
            return true;
        }

        // Base Case: If one is empty, the other isn't, return false, they don't match
        if (p == nullptr && q != nullptr || p != nullptr && q == nullptr){
            return false;
        }

        if (p->val != q->val){
            return false;
        }

        bool leftCall = isSameTree(p->left, q->left);

        bool rightCall = isSameTree(p->right, q->right);


        return leftCall && rightCall;
    }
};
