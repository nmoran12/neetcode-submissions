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

    int diameter = 0;

    int height(TreeNode* thisNode){
        if (!thisNode) return 0;

        int leftChild = height(thisNode->left);
        int rightChild = height(thisNode->right);

        diameter = max(diameter, leftChild + rightChild);

        return 1 + max(leftChild, rightChild);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;


        int maxHeight = height(root);



        return diameter;
    }
};
