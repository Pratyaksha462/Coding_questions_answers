// https://leetcode.com/problems/reverse-string/?utm_source=instabyte.io&utm_medium=referral&utm_campaign=interview-master-100
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int start = 0;
        int end = s.size() - 1;
        while (start <= end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};
