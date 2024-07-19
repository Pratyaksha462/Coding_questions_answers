#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
        int prefix_sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (auto i : nums) {
            prefix_sum += i;
            int mod = prefix_sum % k;
            if (mod< 0)
                mod += k;
            if (mp.find(mod) != mp.end()) {
                count += mp[mod];
                mp[mod]++;
            } else
                mp[mod]=1;
        }
        return count;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    int t=1;
    cin>>t;
   
    return 0;
}