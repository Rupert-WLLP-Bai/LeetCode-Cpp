#include "core.h"
#include <queue>
#include <tuple>

using namespace std;

// 1. 求所有左叶子节点的和
int sumOfLeftLeaves(TreeNode *root) {
    // 使用非递归的方式进行遍历
    if (root == nullptr) {
        return 0;
    }
    stack<TreeNode *> s;
    s.push(root);
    int sum = 0;
    while (!s.empty()) {
        TreeNode *node = s.top();
        s.pop();
        // 存在左子树
        if (node->left != nullptr) {
            // 判断是否为左叶子节点, 即左子树的左右子树都为空
            if (node->left->left == nullptr && node->left->right == nullptr) {
                sum += node->left->val; // 累加左叶子节点的值
            } else {
                s.push(node->left); // 放入左子树
            }
        }

        // 左子树遍历完毕, 遍历右子树
        if (node->right != nullptr) {
            s.push(node->right);
        }
    }
    return sum;
}

// 2. m个n大小的有序数组求并集 使用归并
vector<int> mergeArrays(vector<vector<int>> &arrays) {
    int m = arrays.size();
    int n = arrays[0].size();
    // 使用m路归并
    // 当前元素/数组索引/元素在数组中的索引
    typedef tuple<int, int, int> Element;
    auto cmp = [](Element &a, Element &b) { return get<0>(a) > get<0>(b); };
    priority_queue<Element, vector<Element>, decltype(cmp)> q(cmp);
    vector<int> res;
    // 放入每个数组的第一个元素
    for (int i = 0; i < m; i++) {
        q.push({arrays[i][0], i, 0});
    }
    // 归并
    while (!q.empty()) {
        auto [val, arrayIndex, index] = q.top(); // 取出最小的元素
        cout << "val = " << val << " arrayIndex = " << arrayIndex
             << " index = " << index << endl;
        q.pop();
        // 判断res中是否有元素, 如果有, 判断是否和res中的最后一个元素相等
        if (res.empty() || res.back() != val) {
            res.push_back(val);
        }

        // 判断当前arrayIndex所在的数组是否还有元素
        if (index + 1 < n) {
            q.push({arrays[arrayIndex][index + 1], arrayIndex, index + 1});
        }
    }
    return res;
}

void mergedArraysTest() {
    vector<vector<int>> arrays = {{1, 3, 5}, {2, 4, 6}, {3, 5, 7}};
    vector<int> res = mergeArrays(arrays);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    mergedArraysTest();
    return 0;
}