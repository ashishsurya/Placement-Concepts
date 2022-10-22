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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzag;
  if (root == NULL)
    return zigzag;

  queue<TreeNode *> q;
  q.push(root);
  bool LtoR = true; // to ckec whether to add elements in reverse order.

  while(!q.empty()) {
    int size = q.size();
    vector<int> level(size);

    for (int i = 0; i < size;i++) {
      TreeNode *front = q.front();
      q.pop();

      int index = LtoR ? i : size - i - 1;
      if(front->left) {
        q.push(front->left);
      }
      if(front->right) {
        q.push(front->right);
      }
        
    level[index] = front->val;
    

    }
    zigzag.push_back(level);
    LtoR = !LtoR;
  }

  return zigzag;
    }
};
