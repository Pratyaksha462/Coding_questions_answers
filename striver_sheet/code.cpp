// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<int> lastConflict(n + 1, 0);

//     for (int i = 0; i < m; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         if (x > y)
//             swap(x, y);
//         lastConflict[y] = max(lastConflict[y], x);
//     }

//     int validStart = 1;
//     long long result = 0;

//     for (int b = 1; b <= n; b++)
//     {
//         validStart = max(validStart, lastConflict[b] + 1);
//         result += (b - validStart + 1);
//     }

//     cout << result << endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int c = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] > a[i])
        {
            int k = a[i - 1] - a[i];
            c += k;
            a[i] += k;
        }
    }
    cout << c << endl;
}