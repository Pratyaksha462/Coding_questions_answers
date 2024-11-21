#include <bits/stdc++.h>
using namespace std;
int partition(vector<int> &a, int low, int high)
{
    int pi = a[high];
    int i = low - 1;
    for (int j = low; j <= high; j++)
    {
        if (a[j] < pi)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}
int quicksort(vector<int> &a, int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        quicksort(a, low, pi - 1);
        quicksort(a, pi + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
}