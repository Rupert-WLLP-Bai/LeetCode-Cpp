#include "../../../../include/bintree.h"
#include <unordered_set>

class FindElements {
  public:
    /**
     * @brief LC 1261. 在受污染的二叉树中查找元素
     *
     * @param root
     */
    FindElements(TreeNode *root) {
        root->val = 0;
        s.insert(0);
        recover(root);
        this->root = root;
    }

    bool find(int target) {
        return find(root, target);
    }

  private:
    TreeNode *root;
    unordered_set<int> s; // 存储所有节点 便于查找
    void recover(TreeNode *root) {
        if (root->left) {
            root->left->val = 2 * root->val + 1;
            s.insert(root->left->val);
            recover(root->left);
        }
        if (root->right) {
            root->right->val = 2 * root->val + 2;
            s.insert(root->right->val);
            recover(root->right);
        }
    }

    bool find(TreeNode *root, int target) {
        return s.find(target) != s.end();
    }
};

int main() {
    vector<int> nums = {-1, INT_MIN, -1};
    auto root = buildTree(nums);
    FindElements s(root);
    cout << s.find(1) << endl;
    cout << s.find(2) << endl;
    return 0;
}