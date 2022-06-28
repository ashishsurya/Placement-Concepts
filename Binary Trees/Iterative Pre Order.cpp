#include "BinaryTreeNode.h"
#include <bits/stdc++.h>

std::vector<int> preOrder(BinaryTreeNode<int> *root)
{
  std::vector<int> preorder;

  if (!root)
    return preorder;

  // stack for storing the children of current node.
  std::stack<BinaryTreeNode<int> *> s;
  s.push(root);

  while (!s.empty())
  {
    BinaryTreeNode<int> *top = s.top();
    s.pop();
    preorder.push_back(top->data);
    if (top->right)
      s.push(top->right);
    if (top->left)
      s.push(top->left);
  }

  return preorder;
}
