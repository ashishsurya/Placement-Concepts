#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
  unordered_map<int, int> map;
  vector<int> ans;
  for (int i = 0; i < nums.size(); i++)
  {
    if(map.count(nums[i]) > 0) {
      ans.push_back(i);
      ans.push_back(map[nums[i]]);
      return ans;
    }
    else
    {
      int complement = target-nums[i];
      map[complement] = i;
    }
  }

  return ans;
}

int main()
{
  vector<int> nums = {11, 7, 2, 5};
  int target = 9;
  vector<int> indicies = twoSum(nums, target);

  for(int i:indicies) {
    cout << i << " ";
  }

  return 0;
}
