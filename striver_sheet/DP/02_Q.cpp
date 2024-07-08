#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int index(vector<int> &height, int ind, vector<int> &dp, int k)
    {

        int steps = INT_MAX;
        int jump;
        if (ind == 0)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        for (int j = 1; j <= k; j++)
        {
            if (ind - j >= 0)
            {
                jump = index(height, ind - j, dp, k) + abs(height[ind] - height[ind - j]);
                steps = min(steps, jump);
            }
        }
        return dp[ind] = steps;
    }

    int minimizeCost(vector<int> &height, int n, int k)
    {
        // Code here
        vector<int> dp(n, -1);
        int ans = index(height, n - 1, dp, k);
        return ans;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
