#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

/*
 The basic idea is checking left and right heights of every node.
*/

int height(BinaryTreeNode<int> *root)
{
  if (root == nullptr)
    return 0;

  int leftHeight = height(root->left);
  if (leftHeight == -1)
    return -1;
  int rightHeight = height(root->right);
  if (rightHeight == -1)
    return -1;

  if (abs(leftHeight - rightHeight) > 1)
    return -1;
  return 1 + max(leftHeight, rightHeight);
}

bool isBalanced(BinaryTreeNode<int> *root)
{
  return height(root) != -1;
}