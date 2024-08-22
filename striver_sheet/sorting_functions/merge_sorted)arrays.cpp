// Merge Two Sorted Arrays
#include <bits/stdc++.h>
using namespace std;
vector<int> solve(const vector<int> &A, const vector<int> &B)
{
    bool sortAsc = true;
    if (A[0] > A[A.size() - 1])
    {
        sortAsc = false;
    }
    vector<int> ans;
    int i, j;
    for (i = 0, j = 0; i < A.size() && j < B.size();)
    {
        if (sortAsc)
        {
            if (A[i] < B[j])
            {
                ans.push_back(A[i]);
                i++;
            }
            else
            {
                ans.push_back(B[j]);
                j++;
            }
        }
        else
        {
            if (A[i] > B[j])
            {
                ans.push_back(A[i]);
                i++;
            }
            else
            {
                ans.push_back(B[j]);
                j++;
            }
        }
    }
    while (i < A.size())
    {
        ans.push_back(A[i]);
        i++;
    }
    while (j < B.size())
    {
        ans.push_back(B[j]);
        j++;
    }
    return ans;
}
