#include "../../../../include/bintree.h"
#include <climits>

class Solution {
  public:
    /**
     * @brief LC 530. 二叉搜索树的最小绝对差
     *
     * @param root
     * @return int
     */
    int getMinimumDifference(TreeNode *root) {
        // 中序遍历
        vector<int> nums;
        inorder(root, nums);
        // 求一个有序数组中相邻元素的最小差值
        int minDiff = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            minDiff = min(minDiff, nums[i] - nums[i - 1]);
        }
        return minDiff;
    }

  private:
    void inorder(TreeNode *root, vector<int> &nums) {
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        // 中序遍历 先找到最左边的节点
        while (cur || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            nums.push_back(cur->val);
            cur = cur->right;
        }
    }
};

int main() {
    vector<int> nums = {1, 0, 48, INT_MIN, INT_MIN, 12, 49};
    TreeNode *root = buildTree(nums);
    Solution s;
    cout << s.getMinimumDifference(root) << endl;
    return 0;
}