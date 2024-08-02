# Finding Permutation All Cases

## Case 1 : Permutation of a string: Backtracking
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
### Solution
* In this function, if the value of  L and R is the same then print the same string
* Else run a for loop from L to R and swap the current element in the for loop with the inputString[L]
* Then again call this same function by increasing the value of L by 1
After that again swap the previously swapped values to initiate backtracking.
```cpp
class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans,
                   vector<int>& curr, vector < bool>& visited) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i])
                continue;

            if (i > 0 && nums[i] == nums[i - 1] && !visited[i-1])
                continue;
            visited[i] = true;
            curr.push_back(nums[i]);
            backtrack(nums, ans, curr, visited);
            visited[i] = false;
            curr.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<bool> visited((int)nums.size(), false);
        vector<int> curr;

        backtrack(nums,ans,curr,visited);
        return ans;
    }
};
```

# Permutation of Strings
