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
    int goodNodes(TreeNode* root, int max) {
        if (root == nullptr) {
            return 0;
        }

        int res = 0;
        if (root->val >= max) {
            res++;
            res += goodNodes(root->left, root->val);
            res += goodNodes(root->right, root->val);
        }
        else {
            res += goodNodes(root->left, max);
            res += goodNodes(root->right, max);
        }

        return res;
    }

    int goodNodes(TreeNode* root) {
        return goodNodes(root, INT_MIN);
    }
};