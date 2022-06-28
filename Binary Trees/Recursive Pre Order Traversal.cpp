#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;


void preOrderTraversal(BinaryTreeNode<int> * root) {
  if (root == nullptr) return;
  cout << root->data << endl;
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}