#include<bits/stdc++.h>
using namespace std;

bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            cout << low << " " << high << endl;
            if (nums[mid] == target)
            {
              return true;
            }
            else if (nums[low] <= nums[mid])
            {
              if (nums[low] <= target && target <= nums[mid])
              {
                high = mid - 1;
              }
              else
              {
                low = mid + 1;
              }
            }
            else if (nums[mid] <= nums[high])
            {
              if (nums[mid] <= target && target <= nums[high])
              { // target is present in right sorted array
                low = mid + 1;
              }
              else
              {
                high = mid - 1;
              }
            }
        }
        return false;
    }

int main() {
  vector<int> nums = {1,0,1,1,1};
  int target = 0;
  cout << search(nums, target) << endl;
  return 0;
}
