#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;

        int sum = 0;
        int l, r;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            l = i + 1;
            r = nums.size() - 1;
            vector<int> a1;
            while (l < r)
            {
                int h = nums[i] + nums[l] + nums[r];

                if (h == sum)
                {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while (nums[l] == nums[l - 1] && l < r)
                    {
                        l++;
                    }
                }
                else if (h < sum)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        return ans;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}