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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Reverse so we can treat preorder like a stack, and so 
        // popping is an O(1) op
        reverse(preorder.begin(), preorder.end());

        // map to find the index of any node in inorder
        map<int, int> dict;
        for (int i = 0; i < inorder.size(); i++) {
            dict[inorder[i]] = i;
        }
        
        return buildTree(preorder, dict, 0, preorder.size() - 1);
    }

    TreeNode* buildTree(vector<int>& preorder, map<int, int>& inorder, int l, int r) {
        if (preorder.empty()) {
            return nullptr;
        }
        
        int currIdx = inorder[preorder.back()];
        if (currIdx > r || currIdx < l) {
            return nullptr;
        }

        TreeNode* curr = new TreeNode(preorder.back());
        preorder.pop_back();

        // The left element must be to the left of curr inside
        // the inorder array
        curr->left = buildTree(preorder, inorder, l, currIdx);

        // Similarly right ndoe must be to the right
        curr->right = buildTree(preorder, inorder, currIdx, r);

        return curr;
    }
};