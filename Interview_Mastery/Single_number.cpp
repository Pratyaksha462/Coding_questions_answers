#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/single-number/?utm_source=instabyte.io&utm_medium=referral&utm_campaign=interview-master-100

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};