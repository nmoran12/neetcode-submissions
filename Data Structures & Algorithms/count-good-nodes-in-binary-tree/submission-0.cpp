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
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        int maxValue = 0;

        int leftCount = 0;
        int rightCount = 0;


        goodNodes(root->left);
        if (root->val >= maxValue){
            leftCount++;
            maxValue = root->val;
        }

        goodNodes(root->right);
        if (root->val >= maxValue){
            rightCount++;
            maxValue = root->val;
        }
        
        return 1 + leftCount + rightCount;
    }
};
