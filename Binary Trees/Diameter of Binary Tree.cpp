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


    int diameterOfBinaryTree(TreeNode *root, int &d) {
      if (root == nullptr)
        return 0;
      int leftHeight = diameterOfBinaryTree(root->left, d);
      int rightheight = diameterOfBinaryTree(root->right, d);
      d = max(d, leftHeight + rightheight);
      return 1 + max(leftHeight, rightheight);
    }

    int diameterOfBinaryTree(TreeNode *root) {
      int max = 0;
      diameterOfBinaryTree(root, max);
      return max;
    }
};
