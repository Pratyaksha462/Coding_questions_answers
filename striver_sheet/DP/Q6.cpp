// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     int t = 1;
//     // cin>>t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         int k;
//         cin >> k;
//         vector<int> v(n + 1);
//         v[0] = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             v[i] = i;
//         }

//         // for (int i1 = 1; i1 <= n; i1++)
//         //     cout << v[i1] << " ";

//         cout << endl;

//         int left_num = n;
//         int i = 1;
//         int k_pointer = 1;
//         while (true)
//         {
//             if (i == n)
//                 i = 0;
//             if (left_num == 0)
//                 break;
//             // if (i == n)
//             //     i = 1;
//             // if (v[i] == -1 && i != 0 && k_pointer != 0)
//             // {
//             //     continue;
//             // }
//             if (k_pointer == k)
//             {
//                 v[i] = -1;
//                 left_num--;
//                 k_pointer = ;
//             }
//             i++;
//             if (v[i] != -1)
//             {
//                 k_pointer++;
//             }

//             cout << "vector values" << endl;
//             for (int i1 = 1; i1 <= n; i1++)
//                 cout << v[i1] << " ";

//             cout << " " << i << " " << k_pointer << endl;
//         }
//     }
//     return 0;
// }