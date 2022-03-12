//
// Created by newbie on 2022/3/5.
//
class Solution {
public:
    int addDigits(int num) {
        if (num == 0) {
            return 0;
        }
        return (num - 1) % 9 + 1;
    }
};
