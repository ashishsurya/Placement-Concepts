#include "BinaryTreeNode.h"
#include <bits/stdc++.h>

std::vector<int> inOrder(BinaryTreeNode<int> *root)
{
  std::vector<int> inorder;
  BinaryTreeNode<int> *node = root;

  std::stack<BinaryTreeNode<int> *> st;
  while (true)
  {
    if (node != nullptr)
    {
      st.push(node);
      node = node->left;
    }
    else
    {
      if (st.empty())
        break;
      node = st.top();
      st.pop();
      inorder.push_back(node->data);
      node = node->right;
    }
  }
}