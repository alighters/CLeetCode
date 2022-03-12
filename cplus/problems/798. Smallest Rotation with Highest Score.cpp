//
// Created by newbie on 2022/3/12.
//
using namespace std;
#include "vector"
#include "algorithm"

class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n + 2);
        for (int i = 0; i < n; i++ ) {
            int num = nums[i];
            int left = 0;
            int right = min(i, i - num);
            if (left <= right) {
                count[left] += 1;
                count[right + 1] -= 1;
            }
            left = i;
            right = min(n + i - num, n);
            if (left < right) {
                count[left + 1] += 1;
                count[right + 1] -= 1;
            }
        }
        for (int i = 1; i < n + 2; i ++ ) {
            count[i] += count[i - 1];
        }
        int ma = -1;
        int res = 0;
        for (int i = 0; i < n; i ++) {
            if (count[i] > ma) {
                ma = count[i];
                res = i;
            }
        }
        return res;
    }
};