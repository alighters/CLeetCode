//
// Created by newbie on 2022/3/11.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;



class MedianFinder {
public:
    priority_queue<int, vector<int>, less<>> leftMax;
    priority_queue<int, vector<int>, greater<int>> rightMin;

    MedianFinder() {}

    void addNum(int num) {
        if (leftMax.empty() || leftMax.top() >= num) {
            leftMax.push(num);
            if (leftMax.size() - rightMin.size() > 1) {
                rightMin.push(leftMax.top());
                leftMax.pop();
            }
        } else {
            rightMin.push(num);
            if (rightMin.size() - leftMax.size() > 0){
                leftMax.push(rightMin.top());
                rightMin.pop();
            }
        }
    }

    double findMedian() {
        if (leftMax.size() > rightMin.size()) {
            return leftMax.top();
        } else {
            return (leftMax.top() + rightMin.top()) * 1.0 / 2;
        }
    }
};



/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */