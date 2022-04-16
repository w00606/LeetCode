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
    int max(int a, int b, int c) {
        if (a > b && a > c) {
            return a;
        }
        else if (b > c) {
            return b;
        }
        else {
            return c;
        }
    }
    int traverse_tree(TreeNode* node, int max_depth) {
        ++max_depth;
        int depth_left = 0, depth_right = 0;
        if (node->left != NULL) {
            depth_left = traverse_tree(node->left, max_depth);
        }
        if (node->right != NULL) {
            depth_right = traverse_tree(node->right, max_depth);
        }
        return max(max_depth, depth_left, depth_right);
    }
        
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        if (root != NULL) {
            max_depth = traverse_tree(root, max_depth);
        }
        return max_depth;
    }
};