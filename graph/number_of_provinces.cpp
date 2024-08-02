#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int node, vector<int>& visited, vector<vector<int>>& adj) {
        visited[node] = 1;
        for (auto i : adj[node]) {
            if (!visited[i]) {
                dfs(i, visited, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    int u = i;
                    int v = j;
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
        vector<int> visited(n, 0);

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, visited, adj);
            }
        }
        return count;
    }
};