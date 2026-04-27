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


    vector<int> sortedValues;


        void helper(TreeNode* root){
        if (!root){
            return;
        }


        helper(root->left);
        sortedValues.push_back(root->val);
        //cout << "Sorted Values: " << sortedValues.pop() << endl;
        helper(root->right);
        return;
    }

    int kthSmallest(TreeNode* root, int k) {
        
        helper(root);
        int smallestVal = 0;
        int actualIndex = k - 1;

        int output = sortedValues.at(actualIndex);




        return output;

    }
};
