#include <BinaryTreeNode.h>
#include <bits/stdc++.h>

bool isIdentical(BinaryTreeNode<int> *p, BinaryTreeNode<int> *q)
{
  if (p == nullptr || q == nullptr)
  {
    return p == q;
  }

  return (p->data == q->data) && isIdentical(p->left, q->left) && isIdentical(p->right, q->right);
}