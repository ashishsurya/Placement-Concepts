#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
/*
  Given root of binary tree return its maximum depth
*/

int maxDepth(BinaryTreeNode<int> *root)
{
  if (root == nullptr)
    return 0;

  return 1 + max(maxDepth(root->left), maxDepth(root->right));
}