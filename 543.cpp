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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        diameterOfBinaryTreeInternal(root, diameter);
        return diameter;
    }

    int diameterOfBinaryTreeInternal(TreeNode* node, int& diameter) {
        if (node == nullptr) {
            return 0;
        }
        int leftDiameter = diameterOfBinaryTreeInternal(node->left, diameter);
        int rightDiameter = diameterOfBinaryTreeInternal(node->right, diameter);
        diameter = max(leftDiameter + rightDiameter, diameter);
        return max(leftDiameter, rightDiameter) + 1;
    }
};