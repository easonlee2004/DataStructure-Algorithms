#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

/**
 * @class BTreeNode
 * @brief B树节点类
 * @tparam T 关键字类型
 */
template <typename T>
class BTreeNode {
public:
    bool isLeaf;                  // 是否为叶子节点
    vector<T> keys;               // 存储关键字的数组
    vector<BTreeNode*> children;  // 子节点指针数组
    int numKeys;                  // 当前节点关键字数量

    /**
     * @brief 构造函数
     * @param t 最小度数
     * @param leaf 是否为叶子节点
     */
    BTreeNode(int t, bool leaf) : isLeaf(leaf), numKeys(0) {
        keys.resize(2 * t - 1);   // 预留最大关键字空间
        children.resize(2 * t);   // 预留最大子节点空间
    }

    /**
     * @brief 在未满节点中插入关键字
     * @param key 待插入关键字
     */
    void insertNonFull(T key) {
        int i = numKeys - 1;
        if (isLeaf) {
            // 叶子节点：直接插入并排序
            while (i >= 0 && key < keys[i]) {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = key;
            numKeys++;
        } else {
            // 内部节点：递归向下查找插入位置
            while (i >= 0 && key < keys[i]) i--;
            int childIdx = i + 1;
            if (children[childIdx]->numKeys == 2 * children.size() - 1) {
                // 子节点已满，先分裂
                splitChild(childIdx, children[childIdx]);
                if (key > keys[childIdx]) childIdx++;
            }
            children[childIdx]->insertNonFull(key);
        }
    }

    /**
     * @brief 分裂子节点（核心维护操作）
     * @param idx 子节点索引
     * @param child 待分裂的子节点
     */
    void splitChild(int idx, BTreeNode* child) {
        BTreeNode* newNode = new BTreeNode(child->children.size(), child->isLeaf);
        newNode->numKeys = children.size() - 1;  // 新节点容纳 t-1 个关键字

        // 复制后 t-1 个关键字到新节点
        for (int j = 0; j < children.size() - 1; j++) {
            newNode->keys[j] = child->keys[j + children.size()];
        }

        // 若非叶节点，复制后 t 个子节点
        if (!child->isLeaf) {
            for (int j = 0; j < children.size(); j++) {
                newNode->children[j] = child->children[j + children.size()];
            }
        }

        child->numKeys = children.size() - 1;  // 原子节点保留前 t-1 个关键字

        // 将新节点插入当前节点
        for (int j = numKeys; j > idx; j--) {
            children[j + 1] = children[j];
        }
        children[idx + 1] = newNode;

        for (int j = numKeys - 1; j >= idx; j--) {
            keys[j + 1] = keys[j];
        }
        keys[idx] = child->keys[children.size() - 1];  // 提升中间关键字
        numKeys++;
    }

    /**
     * @brief 查找关键字
     * @param key 目标关键字
     * @return 包含关键字的节点指针（若不存在返回nullptr）
     */
    BTreeNode* search(T key) {
        int i = 0;
        while (i < numKeys && key > keys[i]) i++;
        if (i < numKeys && keys[i] == key) return this;
        if (isLeaf) return nullptr;
        return children[i]->search(key);
    }

    /**
     * @brief 中序遍历（按升序输出关键字）
     */
    void traverse() {
        for (int i = 0; i < numKeys; i++) {
            if (!isLeaf) children[i]->traverse();
            cout << keys[i] << " ";
        }
        if (!isLeaf) children[numKeys]->traverse();
    }

    // 析构函数释放内存
    ~BTreeNode() {
        for (auto child : children) {
            if (child) delete child;
        }
    }
};

/**
 * @class BTree
 * @brief B树管理类
 * @tparam T 关键字类型
 */
template <typename T>
class BTree {
private:
    BTreeNode<T>* root;  // 根节点
    int t;               // 最小度数

public:
    BTree(int degree) : root(nullptr), t(degree) {}

    /**
     * @brief 插入关键字
     * @param key 待插入关键字
     */
    void insert(T key) {
        if (root == nullptr) {
            root = new BTreeNode<T>(t, true);
            root->keys[0] = key;
            root->numKeys = 1;
        } else {
            if (root->numKeys == 2 * t - 1) {
                // 根节点已满，创建新根并分裂
                BTreeNode<T>* newRoot = new BTreeNode<T>(t, false);
                newRoot->children[0] = root;
                newRoot->splitChild(0, root);
                // 确定关键字应插入哪个子节点
                int i = 0;
                if (newRoot->keys[0] < key) i++;
                newRoot->children[i]->insertNonFull(key);
                root = newRoot;
            } else {
                root->insertNonFull(key);
            }
        }
    }

    // 查找关键字
    BTreeNode<T>* search(T key) {
        return root ? root->search(key) : nullptr;
    }

    // 中序遍历
    void traverse() {
        if (root) {
            root->traverse();
            cout << endl;
        }
    }

    ~BTree() {
        if (root) delete root;
    }
};

// 测试函数
int main() {
    BTree<int> btree(3);  // 创建最小度数 t=3 的B树

    // 插入测试数据
    vector<int> keys = {10, 20, 5, 6, 12, 30, 7, 17};
    for (int key : keys) {
        btree.insert(key);
    }

    cout << "B树中序遍历结果: ";
    btree.traverse();  // 输出: 5 6 7 10 12 17 20 30

    int searchKey = 12;
    cout << "查找关键字 " << searchKey << ": "
         << (btree.search(searchKey) ? "存在" : "不存在") << endl;  // 存在

    searchKey = 15;
    cout << "查找关键字 " << searchKey << ": "
         << (btree.search(searchKey) ? "存在" : "不存在") << endl;  // 不存在

    return 0;
}