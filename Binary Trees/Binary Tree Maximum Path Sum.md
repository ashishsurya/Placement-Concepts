# Binary Tree Maximum Path Sum

https://leetcode.com/problems/binary-tree-maximum-path-sum


```cpp
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
    int maxPathSum(TreeNode* root , int &d) {
        if(root == NULL) {
            return 0;
        }

        int maxLeftSum = max(0 , maxPathSum(root->left , d));
        int maxRightSum = max(0 , maxPathSum(root->right , d));
        d = max(d , root->val + maxLeftSum + maxRightSum);
        return root->val + max(maxLeftSum ,maxRightSum);
    }
    int maxPathSum(TreeNode* root) {
        int d = INT_MIN;
        maxPathSum(root , d);
        return d;
    }

    
};
```
