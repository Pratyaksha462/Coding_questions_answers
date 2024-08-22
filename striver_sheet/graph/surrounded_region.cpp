#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &vis,
             vector<vector<char>> &board, int delrow[], int delcol[])
    {
        vis[row][col] = 1;
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < 4; i++)
        {
            int nr = row + delrow[i];
            int nc = col + delcol[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] &&
                board[nr][nc] == 'O')
                dfs(nr, nc, vis, board, delrow, delcol);
        }
    }
    void solve(vector<vector<char>> &board)
    {
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++)
        {
            if (!vis[0][j] && board[0][j] == 'O')
                dfs(0, j, vis, board, delrow, delcol);

            if (!vis[n - 1][j] && board[n - 1][j] == 'O')
                dfs(n - 1, j, vis, board, delrow, delcol);
        }
        for (int i = 0; i < n; i++)
        {
            if (!vis[i][0] && board[i][0] == 'O')
                dfs(i, 0, vis, board, delrow, delcol);

            if (!vis[i][m - 1] && board[i][m - 1] == 'O')
                dfs(i, m - 1, vis, board, delrow, delcol);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};