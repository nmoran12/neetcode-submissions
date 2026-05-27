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

    // Inspector: Check if two trees are identical clones
    // So this is the part that scans the subtree to check if it matches
    // subroot
    bool inspector(TreeNode* a, TreeNode* b){
        //if (!root) return false;

        //if both reach the end (i.e. nullptr), they match perfectly
        if (!a && !b) return true;

        // if one is empty and other isn't, fail
        if (!a || !b) return false;

        // if values don't match, fail
        if (a->val != b->val) return false;

        return inspector(a->left, b->left) && inspector(a->right, b->right);
    }


    // Scout: Traverses the main tree looking for a starting node
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // If it explores and goes out of bounds, it never found a starting node
        // so just return false.
        if (!root) return false;

        // isSubTree pauses at current node, it passes current 'root' and 'subRoot' value
        // to inspector function, and inspector function runs until it returns either a true or false
        // if inspector returns true, this if statement just immediately returns true
        // if it returns false, we go out of the if statement and just continue on down
        // to keep searching the left and right branches.
        bool checkForSubrootValue = inspector(root, subRoot);

        if (checkForSubrootValue == true){
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
