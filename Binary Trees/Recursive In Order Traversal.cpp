#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

void inOrderTraversal(BinaryTreeNode<int> *root)
{
  if (root == nullptr)
    return;
  inOrderTraversal(root->left);
  cout << root->data << endl;
  inOrderTraversal(root->right);
}