# Print Unique Subsets of an array
```cpp
class Solution {
public:
    void f(int idx, vector<int> nums , vector<int> & ds , set<vector<int>> & ans) {
        if(idx == nums.size()){
            ans.insert(ds);
            return;
        }
        ds.push_back(nums[idx]);
        f(idx+1,nums,ds,ans);
        ds.pop_back();
        f(idx+1,nums,ds,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<int> ds;
        f(0,nums,ds,ans);
        vector<vector<int>> ANS;
        for(auto v : ans) {
            ANS.push_back(vector<int>(v.begin(),v.end()));
        }
        return ANS;
    }
};
```
