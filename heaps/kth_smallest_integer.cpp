#include <bits/stdc++.h>
using namespace std;

int kthsmallest(const vector<int> &A, int B)
{
    priority_queue<int> pq;

    for (int i = 0; i < A.size(); i++)
    {
        pq.push(A[i]);
        if (pq.size() > B)
            pq.pop();
    }
    return pq.top();
}
