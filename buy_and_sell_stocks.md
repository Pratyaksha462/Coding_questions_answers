
## Buy and Sell Stock I
Question : You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

``` cpp
Solution :
//Use simple array method

int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int min = prices[0];
        for (int i = 0; i < prices.size(); i++) {
            if (min > prices[i]) {
                min = prices[i];
            } else if (maxprofit < (prices[i] - min)) {
                maxprofit= prices[i] - min;
            }
        }
        return maxprofit;
    }
```
## Buy and Sell Stock II
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

Input: prices = [7,1,5,3,6,4] 

Output: 7

Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.


```cpp
//using memoziation

class Solution {
public:
    int solve(int index, int buy, vector<int>& prices, int n, vector<vector<int>>& dp) {
        if (index == n)
            return 0;
        int profit = 0;
        if (dp[index][buy] != -1)
            return dp[index][buy];
        if (buy == 0) {
            profit = max((0 + solve(index + 1, 0, prices, n, dp)),
                         (-prices[index] + solve(index + 1, 1, prices, n, dp)));
        }
        if (buy == 1) {
            profit = max((0 + solve(index + 1, 1, prices, n, dp)),
                         (prices[index] + solve(index + 1, 0, prices, n, dp)));
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        int ans = solve(0, 0, prices, n, dp);
        return ans;
    }
};
```
## Buy and Sell Stock 3

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

```cpp
class Solution {
public:
    int solve(int index, int buy, int cap, int n, vector<int>& prices,
              vector<vector<vector<int>>>& dp) {
        if (index == n || cap == 0)
            return 0;
        if (dp[index][buy][cap] != -1)
            return dp[index][buy][cap];
        int profit = 0;

        if (buy == 0) {
            profit = max((0 + solve(index + 1, 0, cap, n, prices, dp)),
                         -prices[index] + solve(index + 1, 1, cap, n, prices, dp));
        }
        if (buy == 1) {
            profit =
                max((0 + solve(index + 1, 1, cap, n, prices, dp)),
                    prices[index] + solve(index + 1, 0, cap - 1, n, prices, dp));
        }

        return dp[index][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(3, -1)));
        int ans = solve(0, 0, 2, n, prices, dp);
        return ans;
    }
};
```

## Buy and Sell Stocks IV
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
```cpp
class Solution {
public:
    int solve(int index, int buy, int cap, int n, vector<int>& prices,
              vector<vector<vector<int>>>& dp) {
        if (index == n || cap == 0)
            return 0;

        if (dp[index][buy][cap] != -1)
            return dp[index][buy][cap];
        int profit = 0;

        if (buy == 0) {
            profit = max((0 + solve(index + 1, 0, cap, n, prices, dp)),
                         -prices[index] + solve(index + 1, 1, cap, n, prices, dp));
        }
        if (buy == 1) {
            profit =
                max((0 + solve(index + 1, 1, cap, n, prices, dp)),
                    prices[index] + solve(index + 1, 0, cap - 1, n, prices, dp));
        }

        return dp[index][buy][cap] = profit;
    }
    int maxProfit(int k,vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        int ans = solve(0, 0, k, n, prices, dp);
        return ans;
    }
};
```

## Best Time to Buy and Sell Stock with Cooldown

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

```cpp
class Solution {
public:
    int solve(int index, int buy, vector<int>& prices, int n,
              vector<vector<int>>& dp) {
        if (index >= n)
            return 0;
        int profit = 0;
        if (dp[index][buy] != -1)
            return dp[index][buy];
        if (buy == 0) {
            profit = max((0 + solve(index + 1, 0, prices, n, dp)),
                         (-prices[index] + solve(index + 1, 1, prices, n, dp)));
        }
        if (buy == 1) {
            profit = max((0 + solve(index + 1, 1, prices, n, dp)),
                         (prices[index] + solve(index + 2, 0, prices, n, dp)));
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        int ans = solve(0, 0, prices, n, dp);
        return ans;
    }
};
```
## Buys and Sell Stock With Transaction Fees
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:
You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.
```cpp
class Solution {
public:
    int solve(int index, int buy, int fees,vector<int>& prices, int n,
              vector<vector<int>>& dp) {
        if (index == n)
            return 0;
        int profit = 0;
        if (dp[index][buy] != -1)
            return dp[index][buy];
        if (buy == 0) {
            profit = max(
                (0 + solve(index + 1, 0, fees, prices, n, dp)),
                (-prices[index] + solve(index + 1, 1, fees, prices, n, dp)));
        }
        if (buy == 1) {
            profit = max((0 + solve(index + 1, 1, fees, prices, n, dp)),
                         (prices[index] - fees +
                          solve(index + 1, 0, fees, prices, n, dp)));
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        int ans = solve(0, 0, fee,prices, n, dp);
        return ans;
    }
};
```