#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-subarray/?utm_source=instabyte.io&utm_medium=referral&utm_campaign=interview-master-100
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int maxsum = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (maxsum < sum)
                maxsum = sum;
            if (sum < 0)
                sum = 0;
        }
        return maxsum;
    }
};