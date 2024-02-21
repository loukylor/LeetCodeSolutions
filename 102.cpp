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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return vector<vector<int>>();
        }

        vector<vector<int>> res;
        list<TreeNode*> queue;
        int depth = -1;
        TreeNode* curr;

        queue.push_back(root);

        while (queue.size() != 0) {
            depth++;
            res.push_back(vector<int>());

            int levelSize = queue.size();
            for (int i = 0; i < levelSize; i++) {
                curr = queue.front();
                queue.pop_front();

                if (curr->left != nullptr) {
                    queue.push_back(curr->left);
                }

                if (curr->right != nullptr) {
                    queue.push_back(curr->right);
                }
                
                res[depth].push_back(curr->val);
            }
        }

        return res;
    }
};