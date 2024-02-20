/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = root;
        while (true) {
            if (p->val < res->val && q->val < res->val) {
                res = res->left;
            } else if (p->val > res->val && q->val > res->val) {
                res = res->right;
            } else {
                return res;
            }
        }

        return nullptr;
    }
};