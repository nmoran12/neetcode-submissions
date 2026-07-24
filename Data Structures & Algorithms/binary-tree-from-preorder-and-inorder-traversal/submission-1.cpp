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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int preorderRootValue = preorder[0];
        int inorderRootIndex = 0;
        vector<int> leftSubtree;
        vector<int> rightSubtree;

        vector<int> leftPreorder;
        vector<int> rightPreorder;

        int leftSideSize = 0;
        int rightSideSize = 0;

        TreeNode* root = new TreeNode(preorderRootValue);

        // Finding where the root value is in the inorder tree
        for (int i = 0; i < inorder.size(); i++){
            if (inorder[i] == preorderRootValue){
                inorderRootIndex = i;
                break;
            }
        }

        // Now we know the root index of the inorder traversal tree
        // Populate leftSubtree vector with all values left of root
        for (int i = 0; i < inorderRootIndex; i++){
            leftSideSize++;
            leftSubtree.push_back(inorder[i])
        }

        // Populate rightSubtree vector with all values right of root
        for (int j = inorderRootIndex; j < inorder.size(); j++){
            rightSideSize++;
            rightSubtree.push_back(inorder[j]);
        }

        // Now to figure out preorder traversal tree
        // Left should be leftSideSize loop
        for (int k = 1; k < leftSideSize; k++){
            leftPreorder.push_back(preorder[k]);
        }

        for (int l = leftSideSize; l < rightSideSize; l++){
            rightPreorder.push_back(preorder[l]);
        }

        root->left = buildTree(leftPreorder, leftSubtree);
        root->right = buildTree(rightPreorder, rightSubtree);
        

        return root;
    }
};
