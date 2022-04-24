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
    
    void recurTraverse(TreeNode* node, vector<int>& ret) {
        if (node) {
            recurTraverse(node->left, ret);
            ret.emplace_back(node->val);
            recurTraverse(node->right, ret);   
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        recurTraverse(root, ret);
        return ret;
    }
};