#include "../../../../include/bintree.h"
#include <climits>

class Solution {
  public:
    /**
     * @brief LC 501. 二叉搜索树中的众数
     *
     * @param root
     * @return vector<int>
     */
    vector<int> findMode(TreeNode *root) {
        // 难点: 如何使用常数空间
        // 中序遍历, 用pre记录前一个节点的值, cnt记录当前节点值出现的次数,
        // maxCnt记录最大出现次数, res记录结果
        vector<int> res;
        int pre = INT_MIN, cnt = 0, maxCnt = 0;
        stack<TreeNode *> stk;
        while (root || !stk.empty()) {
            // 整体是中序遍历的顺序
            while (root) {
                stk.push(root);
                root = root->left;
            }
            TreeNode *node = stk.top();
            stk.pop();
            if (pre == node->val) {
                // 如果当前节点值等于前一个节点值, 则cnt++
                cnt++;
            } else {
                // 否则, 重置cnt为1, pre为当前节点值
                cnt = 1;
                pre = node->val;
            }
            if (cnt == maxCnt) {
                // 如果cnt等于maxCnt, 则将当前节点值加入res
                res.push_back(node->val);
            } else if (cnt > maxCnt) {
                // 如果cnt大于maxCnt, 则重置res为当前节点值, maxCnt为cnt
                res.clear();
                res.push_back(node->val);
                maxCnt = cnt;
            }
            root = node->right;
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1, 1, 2, INT_MIN, INT_MIN, 2};
    TreeNode *root = buildTree(nums);
    Solution s;
    vector<int> res = s.findMode(root);
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}