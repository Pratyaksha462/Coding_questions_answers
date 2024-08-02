#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int ans(string a, string b)
    {
        int a1 = stoi(a);
        int b1 = stoi(b);
        return a1;
    }
};
Solution s;
int main()
{
    ios_base::sync_with_stdio(false);
    string a;
    string b;
    cin >> a >> b;
    int ans = s.ans(a, b);
    cout << ans;

    return 0;
}