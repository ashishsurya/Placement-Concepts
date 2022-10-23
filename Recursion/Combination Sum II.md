# Combination Sum II
<img src="https://user-images.githubusercontent.com/72222785/197385060-efa43686-0ffc-4c94-b9e4-c91a794d9d42.png" width="500px"/>

```cpp
class Solution {
public:
    void f(int idx,int n,int target, vector<int> & arr , vector<int> & ds , vector<vector<int>> & ans) {
        if(target == 0) {
            ans.push_back(ds);
            return;
        }
        for(int i=idx;i<n;i++) {
            if(i > idx && arr[i] == arr[i-1]) continue;
            if(arr[i] > target) break;
            ds.push_back(arr[i]);
            f(i+1,n,target - arr[i],arr,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<vector<int>> ans;
        vector<int> ds;
        f(0,n,target,arr,ds,ans);
        return ans;
    }
};
```
