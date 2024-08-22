#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> hash;
        int res = 0;
        int majority = 0;

        for (int n : nums)
        {
            hash[n] = 1 + hash[n];
            if (hash[n] > majority)
            {
                res = n;
                majority = hash[n];
            }
        }

        return res;
    }
};

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int candidate = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
                candidate = nums[i];
            if (nums[i] == candidate)
                count++;
            else
                count--;
        }
        return candidate;
    }
};