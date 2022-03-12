//
// Created by newbie on 2022/3/12.
//

using namespace std;
#include "vector"

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        vector<Node*> stack;
        stack.push_back(root);
        while (!stack.empty()) {
            Node* node = stack.back();
            stack.pop_back();
            res.push_back(node->val);
            for (auto item : node->children) {
                stack.push_back(item);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};