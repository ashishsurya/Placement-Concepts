#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

void postOrderTraversal(BinaryTreeNode<int> *root)
{
  if (root == nullptr)
    return;
  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  cout << root->data << endl;
}