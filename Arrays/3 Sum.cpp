#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int target)
{
  // Write your code here.
  sort(array.begin(), array.end());
  vector<vector<int>> triplets;
  for (int i = 0; i < array.size(); i++)
  { // looping untill 3rd element from last,

    int left = i + 1;
    int right = array.size() - 1;
    while (left < right)
    {
      int currSum = array[i] + array[left] + array[right];
      if (currSum < target)
      {
        left++;
      }
      else if (currSum > target)
      {
        right--;
      }
      else
      {
        cout << array[i] << " " << array[left] << " " << array[right] << endl;
        triplets.push_back({array[i], array[left], array[right]});
        left++;
        right--;
      }
    }
  }
  return triplets;
}

int main(int argc, char const *argv[])
{
  vector<int> array = {12, 3, 1, 2, -6, 5, -8, 6};
  vector<vector<int>> ans = threeNumberSum(array, 0);

  return 0;
}
