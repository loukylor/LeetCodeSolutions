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
    bool isBalanced(TreeNode* root) {
        int temp;
        return isBalancedInternal(root, temp);
    }

    bool isBalancedInternal(TreeNode* node, int& depth) {
        if (node == nullptr) {
            depth = 0;
            return true;
        }

        int lDepth, rDepth;
        bool ret = isBalancedInternal(node->left, lDepth);
        ret &= isBalancedInternal(node->right, rDepth);

        depth = max(lDepth, rDepth) + 1;
        if (!ret || abs(lDepth - rDepth) > 1) {
            return false;
        }
        return true;
    }
};