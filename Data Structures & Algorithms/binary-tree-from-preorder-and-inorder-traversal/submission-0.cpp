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
    int preorderIndex = 0;

    TreeNode* helperTree(vector<int>& preorder, vector<int>& inorder, int inorderStart, int inorderEnd) {
        // Base case: if the boundary is invalid, there are no nodes to build
        if (inorderStart > inorderEnd) return nullptr;

        // Create the current root node
        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);

        // Find the index of the root value within the inorder array
        int inorderIndex = inorderStart;
        while (inorderIndex <= inorderEnd && inorder[inorderIndex] != rootVal) {
            inorderIndex++;
        }

        // Recursively build the left and right subtrees
        root->left = helperTree(preorder, inorder, inorderStart, inorderIndex - 1);
        root->right = helperTree(preorder, inorder, inorderIndex + 1, inorderEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Essential guard: handle empty tree inputs cleanly before calling the helper
        if (preorder.empty() || inorder.empty()) return nullptr;
        
        return helperTree(preorder, inorder, 0, (int)inorder.size() - 1);
    }
};