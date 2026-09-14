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
    // int diameterOfBinaryTree(TreeNode* root) {
    //     if(!root)return 0;
    //     int leftDiameter = 0, rightDiameter = 0;
    //     if(root->left)leftDiameter = 1 + diameterOfBinaryTree(root->left);
    //     if(root->right)rightDiameter = 1 + diameterOfBinaryTree(root->right);
    //     return max(leftDiameter, rightDiameter);
    // }

    int maxHeight(TreeNode *root) {
        if(root==NULL) return 0;
        return 1 + max(maxHeight(root->left), maxHeight(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
       int l_root = diameterOfBinaryTree(root->left);
       int r_root = diameterOfBinaryTree(root->right);
       return max(l_root, max(r_root,  maxHeight(root->left) + maxHeight(root->right)));
    }
};
