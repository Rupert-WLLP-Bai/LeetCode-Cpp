#include "../../../../include/core.h"
using namespace std;

/**
 * @brief LC 208. 实现Trie（前缀树）
 *
 */
class Trie {
  public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *node = root;
        for (char ch : word) {
            int index = ch - 'a'; // 计算下标
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode(); // 如果不存在则新建
            }
            node = node->children[index]; // 指向新的节点
        }
        node->isEnd = true; // 将最后一个节点标记为单词结尾
    }

    bool search(string word) {
        TrieNode *node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index]; // 继续向下遍历，直到找到最后一个节点
        }
        return node->isEnd; // 判断是否是单词结尾
    }

    bool startsWith(string prefix) {
        TrieNode *node = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index]; // 向下遍历
        }
        return true;
    }

    struct TrieNode {
        TrieNode *children[26]; // 26个字母
        bool isEnd;             // 是否是单词结尾
        TrieNode() {
            memset(children, 0, sizeof(children)); // 初始化为nullptr
            isEnd = false;                         // 初始化为false
        }
    };

  private:
    TrieNode *root; // Trie树的根节点
};

int main() {
    Trie *trie = new Trie();
    trie->insert("apple");
    cout << boolalpha;
    cout << trie->search("apple") << endl;   // 返回 true
    cout << trie->search("app") << endl;     // 返回 false
    cout << trie->startsWith("app") << endl; // 返回 true
    trie->insert("app");
    cout << trie->search("app") << endl; // 返回 true
    return 0;
}