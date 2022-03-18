//
// Created by newbie on 2022/3/18.
//
using namespace std;
#include <vector>
#include <iostream>

class NumArray {
    vector<int> nums;
    vector<int> sums;
public:
    NumArray(vector<int>& nums) {
        this -> nums = nums;
        sums = vector<int>(nums.size() + 1, 0);
        for (int index = 0; index < nums.size(); index ++) {
            int i = 1 + index;
            while (i <= nums.size()) {
                sums[i] += nums[index];
                i += i & -i;
            }
        }
    }

    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        int i = 1 + index;
        while (i <= nums.size()) {
            sums[i] += diff;
            i += i & -i;
        }
    }

    int sumRange(int left, int right) {
        return query(right) - query(left - 1);
    }

    int query(int index) {
        int i = index + 1;
        int res = 0;
        while (i > 0) {
            res += sums[i];
            i -= i & -i;
        }
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

//int main() {
//    vector<int> nums;
//    nums.push_back(1);
//    nums.push_back(3);
//    nums.push_back(5);
////    std::cout << nums << std::endl;
//    auto* obj = new NumArray(nums);
//    std::cout << obj->sumRange(0, 2) << std::endl;
//    obj->update(1, 2);
//    std::cout << obj->sumRange(0, 2 ) << std::endl;
//    return 0;
//}