#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int area = 0;
        while (l < r) {
            area = max(area, min(height[r], height[l]) * (r - l));
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return area;
    }
};
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
    
    return 0;
}