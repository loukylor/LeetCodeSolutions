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
    int maxPathSum(TreeNode* root) {
        int temp = 0;
        return maxPathSumInternal(root, temp);
    }
private:
    int maxPathSumInternal(TreeNode* root, int& addableMax) {
        if (root == nullptr) {
            addableMax = 0;
            return INT_MIN;
        }

        int addableLeft;
        int leftCorner = maxPathSumInternal(root->left, addableLeft);

        int addableRight;
        int rightCorner = maxPathSumInternal(root->right, addableRight);

        int corner = addableLeft + addableRight + root->val;
        int parentSide = max(addableLeft + root->val, addableRight + root->val);

        addableMax = max(parentSide, 0);
        return max(leftCorner, max(rightCorner, corner));
    }
};
