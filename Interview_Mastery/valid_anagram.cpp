// https://leetcode.com/problems/valid-anagram/?utm_source=instabyte.io&utm_medium=referral&utm_campaign=interview-master-100

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        map<char, int> mp;
        map<char, int> mp1;
        for (auto i : s)
        {
            mp[i]++;
        }
        for (auto i : t)
        {
            mp1[i]++;
        }
        if (mp == mp1)
            return true;
        else
            return false;
    }
};