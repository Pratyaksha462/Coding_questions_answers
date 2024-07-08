#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, int node)
    {
        int sum1 = INT_MIN;
        if (node < 0)
            return 0;
        sum1 = max((solve(nums, node - 2) + nums[node]), solve(nums, node - 1));

        return sum1;
    }

    int rob(vector<int> &nums)
    {
        int ans = solve(nums, nums.size() - 1);
        return ans;
    }
};