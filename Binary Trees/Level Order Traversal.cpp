#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

vector<vector<int>> levelOrderTraversal(BinaryTreeNode<int> *root)
{
  vector<vector<int>> ans;
  if (root == nullptr)
    return ans;
  queue<BinaryTreeNode<int> *> queue;
  queue.push(root);
  while (!queue.empty())
  {
    int size = queue.size();
    vector<int> level;
    for (int i = 0; i < size; i++)
    {
      BinaryTreeNode<int> *front = queue.front();
      queue.pop();
      if (front->left)
        queue.push(front->left);
      if (front->right)
        queue.push(front->right);
      level.push_back(front->data);
    }
    ans.push_back(level);
  }

  return ans;
}