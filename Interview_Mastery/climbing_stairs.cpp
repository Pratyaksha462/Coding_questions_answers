#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/climbing-stairs/?utm_source=instabyte.io&utm_medium=referral&utm_campaign=interview-master-100

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> t(n + 1);

        t[0] = 1;
        t[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            t[i] = t[i - 1] + t[i - 2];
        }
        return t[n];
    }
};