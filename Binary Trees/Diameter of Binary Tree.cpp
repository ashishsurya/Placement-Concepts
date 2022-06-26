#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

int diameter(BinaryTreeNode<int> *root, int &d)
{
  if (root == nullptr)
    return 0;
  int leftHeight = diameter(root->left, d);
  int rightheight = diameter(root->right, d);
  d = max(d, leftHeight + rightheight);
  return 1 + max(leftHeight, rightheight);
}

int diameter(BinaryTreeNode<int> *root)
{
  int max = 0;
  diameter(root, max);
  return max;
}