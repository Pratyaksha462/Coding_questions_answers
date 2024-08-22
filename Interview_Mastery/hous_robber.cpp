#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> a(n + 1, 0);
        a[1] = nums[0];
        for (int i = 2; i <= n; i++)
        {
            a[i] = max(a[i - 1], a[i - 2] + nums[i - 1]);
        }
        return a[n];
    }
};