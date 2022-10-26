# Partition Set Into 2 Subsets With Min Absolute Sum Diff (DP- 16)

You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.

Return the minimum possible absolute difference.
<br />
<img src="https://assets.leetcode.com/uploads/2021/10/02/ex1.png" width="200px" />

```
Input: nums = [3,9,7,3]
Output: 2
Explanation: One optimal partition is: [3,9] and [7,3].
The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.
```
