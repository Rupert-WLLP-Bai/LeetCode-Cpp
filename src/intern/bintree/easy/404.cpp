#include "../../../../include/bintree.h"
#include <numeric>

class Solution {
  public:
    /**
     * @brief LC 404. 左叶子之和
     *
     * @param root
     * @return int
     */
    int sumOfLeftLeaves(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            if (node != NULL) {
                st.pop();
                if (node->right) st.push(node->right); // 右
                if (node->left) st.push(node->left);   // 左
                st.push(node);                         // 中
                st.push(NULL);
            } else {
                st.pop();
                node = st.top();
                st.pop();
                if (node->left && node->left->left == nullptr &&
                    node->left->right == nullptr) {
                    result.push_back(node->left->val);
                }
            }
        }
        return accumulate(result.begin(), result.end(), 0);
    }
};

int main() {
    vector<int> nums = {3, 9, 20, INT_MIN, INT_MIN, 15, 7};
    TreeNode *root = buildTree(nums);
    Solution s;
    cout << s.sumOfLeftLeaves(root) << endl;
    return 0;
}