#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> numbers(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> numbers[i];
    }
    int target;
    cin >> target;
    vector<int> v;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        if (mp.find(target - numbers[i]) != mp.end())
        {
            v.push_back(mp[numbers[i]]);
            v.push_back(mp[target - numbers[i]]);
            break;
        }

        mp[numbers[i]] = i + 1;
        cout << mp[numbers[i]] << endl;
        cout << mp[target - numbers[i]] << endl;
    }

    return 0;
}