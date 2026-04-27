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

    vector<int> storeNum;

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr || root->val == 0){
            return false;
        }

        storeNum.push_back(root->val);



        if (!root->left && !root->right){
            int sum = 0;
            for (int val : storeNum){
                sum += val;
            }

            bool matches = (sum == targetSum);
            storeNum.pop_back();
            return matches;
        }

        if (hasPathSum(root->left, targetSum)){
            storeNum.pop_back();
            return true;
        }

        if (hasPathSum(root->right, targetSum)){
            storeNum.pop_back();
            return true;
        }



        storeNum.pop_back();

        return false;
    }
};