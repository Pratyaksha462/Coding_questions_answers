#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums, int start, int end, int& count,
               vector<int>& temp) {
        int mid = start + (end - start) / 2;
        int i = start, j = mid + 1, k = start;
        while (i <= mid && j <= end) {
            if (nums[i] > (long long)2 * nums[j]) {
                count += (mid - i + 1);
                j++;
            } else {
                i++;
            }
        }
        i = start;
        j = mid + 1;
        while (i <= mid && j <= end) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        while (j <= end) {
            temp[k++] = nums[j++];
        }
        while (start <= end) {
            nums[start] = temp[start];
            start++;
        }
    }
    void mergesort(vector<int>& nums, int start, int end, int& count,
                   vector<int>& temp) {
        if (start >= end)
            return;
        int mid = start + (end - start) / 2;
        mergesort(nums, start, mid, count, temp);
        mergesort(nums, mid + 1, end, count, temp);
        merge(nums, start, end, count, temp);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int start = 0;
        int end = n - 1;
        vector<int> temp(n);
        mergesort(nums, start, end, count, temp);
        return count;
    }
};