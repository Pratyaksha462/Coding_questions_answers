# Next Greater Element Series

## Next Greater Element I
Problem Link : https://leetcode.com/problems/next-greater-element-i/description/

The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

Solution 
```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        map<int, int> mp;
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (st.size() != 0 && st.top() < nums2[i])
                st.pop();

            if (st.empty() == true) {
                mp[nums2[i]] = -1;

            } else {
                mp[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        vector<int> final_answer;
        for (int i = 0; i < nums1.size(); i++) {
            final_answer.push_back(mp[nums1[i]]);
        }
        return final_answer;
    }
};
```

## Next Greater ELement II

Problem Link : https://leetcode.com/problems/next-greater-element-ii/description/

Problem Description : Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

Approach : Think of the way we need to traverse in the array. Like now we need to run a loop for 2*N elements.


```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; i--) {
            int a = nums[i % n];
            while (!st.empty() && st.top() <= a)
                st.pop();
            if (st.empty())
                ans[i % n] = -1;
            else
                ans[i % n] = st.top();
            st.push(a);
        }
        return ans;
    }
};
```

## Next Greater Element III

Problem Link : https://leetcode.com/problems/next-greater-element-iii/

Description : Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.