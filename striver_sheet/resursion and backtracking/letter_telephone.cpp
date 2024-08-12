#include <bits/stdc++.h>
using namespace std;
unordered_map<char, string> mp = {{'0', "0"}, {'1', "1"}, {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
void solve(string &A, int i, vector<string> &ans, string o)
{
    if (i >= A.size())
    {
        ans.push_back(o);
        return;
    }
    string t = mp[A[i]];
    for (int j = 0; j < t.size(); j++)
    {
        solve(A, i + 1, ans, o + t[j]);
    }
}
vector<string> letterCombinations(string A)
{
    vector<string> ans;
    string o = "";
    if (A.size() == 0)
        return {};
    solve(A, 0, ans, o);
    return ans;
}
