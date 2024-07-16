//https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    int t=1;
    cin>>t;

    return 0;
}