 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> arr = cardPoints;

        int n = cardPoints.size() - 1;
        int score = 0;
        for (int i = 0; i < k; i++) {
            score += arr[i];
        }
        int ans = score;
        k--;
        int i = n;
        while (k >= 0) {
            score = score - arr[k] + arr[i];
            k--;
            i--;
            ans = max(ans, score);
        }
        return ans;
    }
};