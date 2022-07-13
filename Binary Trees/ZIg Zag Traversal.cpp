#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

vector<vector<int>> zigzagTraversal(BinaryTreeNode<int> *root)
{
  vector<vector<int>> zigzag;
  if (root == NULL)
    return zigzag;

  queue<BinaryTreeNode<int> *> q;
  q.push(root);
  bool LtoR = true; // to ckec whether to add elements in reverse order.

  while(!q.empty()) {
    int size = q.size();
    vector<int> level(size);

    for (int i = 0; i < size;i++) {
      BinaryTreeNode<int> *front = q.front();
      q.pop();

      int index = LtoR ? i : size - i - 1;
      if(front->left) {
        q.push(front->left);
      }
      if(front->right) {
        q.push(front->right);
      }

      level[index] = front->data;
    }
    zigzag.push_back(level);
    LtoR = !LtoR;
  }

  return zigzag;
}

int main()
{

  return 0;
}
