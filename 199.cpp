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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return {};
        }

        queue<TreeNode*> traverse;
        traverse.push(root);

        while (!traverse.empty()) {
            // Add right most element to result
            res.push_back(traverse.back()->val);
            
            // Traverse all nodes on current level
            int layerSize = traverse.size();
            for (int i = 0; i < layerSize; i++) {
                // Add all left nodes to traverse queue
                TreeNode* curr = traverse.front();
                traverse.pop();

                if (curr->left != nullptr) {
                    traverse.push(curr->left);
                }

                if (curr->right != nullptr) {
                    traverse.push(curr->right);
                }
            }
        }

        return res;
    }
};