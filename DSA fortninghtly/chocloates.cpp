#include <bits/stdc++.h>
using namespace std;

int solve(int A, vector<int> &B, int C)
{
  priority_queue<int> maxHeap;
  for (auto it : B)
  {
    maxHeap.push(it);
  }

  while (maxHeap.size() != C && maxHeap.top() != 1)
  {
    int currentTop = maxHeap.top();
    maxHeap.pop();
    // now break the top into parts.
    // now push the parts in to the heap.
    maxHeap.push(currentTop - 1);
    maxHeap.push(1);
  }

  if (maxHeap.size() == C)
  {
    return maxHeap.top();
  }
  else
  {
    return -1;
  }
}

int main()
{
  vector<int> v = {550, 362, 126, 583, 451, 469, 57, 199, 451, 698, 936, 229, 291, 466, 363, 1133, 196, 1099, 852, 365, 552, 278, 1031, 730, 712, 295, 1041, 585, 1, 841, 463, 38, 82, 759, 2, 160, 687, 132, 1042, 539, 929, 740, 88, 1181, 1172, 497, 418, 1057, 360, 439, 626, 327, 929, 631, 816, 306, 263, 568, 4, 248, 407, 561, 524, 438, 479, 65, 1164, 986, 406, 1048, 105, 967, 210, 11, 861, 116, 671, 579, 711, 749, 15, 94, 56, 289, 1141, 1069, 870, 994, 809, 293, 492, 728, 615, 334, 200, 846, 847, 1111, 301, 275};
  cout << solve(100, v, 845) << endl;
  return 0;
}
