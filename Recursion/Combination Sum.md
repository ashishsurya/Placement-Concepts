# Combination Sum

picking elements from an array, we should start thinking of **pick/non-picking** strategy.
here combination refers to picking an element any no of times.

```cpp
class Solution {
public:
    void combinationSum(int idx,vector<int>& candidates, int target,vector<vector<int>> & ans, vector<int> & ds) {
        if(idx == candidates.size()) {
            if(target == 0) ans.push_back(ds);
            return;
        }
        if(candidates[idx] <= target) {
            ds.push_back(candidates[idx]);
            combinationSum(idx,candidates,target-candidates[idx],ans,ds);
            ds.pop_back();
        }
        combinationSum(idx+1,candidates,target,ans,ds);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        combinationSum(0,candidates,target,ans,ds);
        return ans;
    }
};
```
