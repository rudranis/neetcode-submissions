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

    int height(TreeNode* root) {

        // Empty tree
        if (root == nullptr)
            return 0;

        // Height of left subtree
        int leftHeight = height(root->left);

        // If left subtree is unbalanced
        if (leftHeight == -1)
            return -1;

        // Height of right subtree
        int rightHeight = height(root->right);

        // If right subtree is unbalanced
        if (rightHeight == -1)
            return -1;

        // Check current node
        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        // Return height of current subtree
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {

        return height(root) != -1;
    }
};
