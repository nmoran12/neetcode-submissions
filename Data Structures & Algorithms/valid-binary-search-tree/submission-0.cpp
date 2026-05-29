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

    bool helperFunc(TreeNode* node, long long leftBound, long long rightBound){
        if (!node) return true;

        // This checks if the curent node value is between the lower bound and upper bound
        // i.e. checks lowerBound <= nodeValue <= upperBound
        if (node->val <= leftBound || node->val >= rightBound){
            return false;
        }


        return helperFunc(node->left, leftBound, node->val) && helperFunc(node->right, node->val, rightBound);
    }



    bool isValidBST(TreeNode* root) {

        return helperFunc(root, LONG_MIN, LONG_MAX);
    }
};
