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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<TreeNode*> stack = { p, q };

        while (stack.size() != 0) {
            TreeNode* tree1 = stack.back();
            stack.pop_back();
            TreeNode* tree2 = stack.back(); 
            stack.pop_back();

            if (tree1 == nullptr || tree2 == nullptr) {
                if ((tree1 == nullptr) != (tree2 == nullptr)) {
                    return false;
                }

                continue;
            }
            else if (tree1->val != tree2->val) {
                return false;
            }

            stack.push_back(tree2->left);
            stack.push_back(tree1->left);
            stack.push_back(tree2->right);
            stack.push_back(tree1->right);
        }   
        return true;     
    }
};