// using reccursion
//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
    void solve(TreeNode* root, TreeNode* &pred) {
        TreeNode* curr = root;
        if(root == NULL)
            return ;
        solve(curr->right, pred);
        solve(curr->left, pred);
        curr->right = pred;
        curr->left = NULL;
        pred = curr;
    } 
public:
    void flatten(TreeNode* root) {
        TreeNode* pred = NULL;
        solve(root, pred);
    }
};
