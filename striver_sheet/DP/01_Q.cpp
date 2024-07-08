// https : // www.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int index(vector<int> &height, int ind, vector<int> &dp)
    {

        int jumpone;
        int jumptwo = INT_MAX;
        if (ind == 0)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        jumpone = index(height, ind - 1, dp) + abs(height[ind] - height[ind - 1]);

        if (ind > 1)
            jumptwo = index(height, ind - 2, dp) + abs(height[ind] - height[ind - 2]);

        return dp[ind] = min(jumpone, jumptwo);
    }
    int minimumEnergy(vector<int> &height, int n)
    {
        // Code here
        vector<int> dp(n, -1);
        int ans = index(height, n - 1, dp);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
