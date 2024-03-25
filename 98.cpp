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
    bool isValidBST(TreeNode* root) {
        // Root is guaranteed to be nonnull
        return isValidBST(root, (long)INT_MIN - 1, (long)INT_MAX + 1);
    }

    bool isValidBST(TreeNode* node, int64_t min_, int64_t max_) {
        if (node == nullptr) {
            return true;
        }

        bool res = (node->val > min_ && node->val < max_);
        return res && isValidBST(node->left, min_, node->val) && isValidBST(node->right, node->val, max_);
    }
};