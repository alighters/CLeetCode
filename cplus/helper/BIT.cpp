//
// Created by newbie on 2022/3/18.
//
#include <vector>

using namespace std;

class BIT {
private:
    vector<int> sums;
    int n;
public:
    BIT(vector<int>& nums) {
        n = nums.size();
        sums = vector<int>(n + 1, 0);
        for (int i = 0; i < n; i ++) {
            update(i, nums[i]);
        }

    }

    void update(int index, int val) {
        int i = 1 + index;
        while (i <= n) {
            sums[i] += val;
            i += i & -i;
        }
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

