#include <algorithm>
#include <cstddef>
#include <iostream>
#include <math.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class tree {
private:
  struct treeNode {
    int val;
    treeNode *right;
    treeNode *left;
    treeNode(int v, treeNode *f, treeNode *n)
        : val(v), right(nullptr), left(nullptr) {}
  };
  treeNode *rootTree;
  void add(treeNode *&root, int val) {

    if (root == nullptr) {
      root = new treeNode(val, nullptr, nullptr);
      return;
    }
    if (root->val > val) {
      add(root->left, val);
      return;
    }
    if (root->val < val) {
      add(root->right, val);
      return;
    }
    return;
  }
  treeNode *search(treeNode *&root, int target) {
    if (root == nullptr)
      return nullptr;
    if (root->val == target) {
      return root;
    }
    if (root->val > target) {
      return search(root->left, target);
    }
    if (root->val < target) {
      return search(root->right, target);
    }
    return nullptr;
  }
  bool del(treeNode *&root, int target) {
    if (!root) {
      return false;
    }
    if (root->val > target) {
      return del(root->left, target);
    }
    if (root->val < target) {
      return del(root->right, target);
    }
    if (!root->right && !root->left) {
      delete root;
      return true;
    }
    if (!root->right || !root->left) {
      treeNode *child = root->right == nullptr ? root->left : root->right;
      delete root;
      root = child;
      return true;
    }
    treeNode *cur = root;

    treeNode *parent = cur;
    cur = cur->right;
    while (cur->left != nullptr) {
      parent = cur;
      cur = cur->left;
    }
    
    // 关键！如果后继节点不是 root->right
    if (parent != root) {
        parent->left = cur->right;
        cur->right = root->right;
    }
    cur->left = root->left;

    delete root;
    root = cur;
    return true;
  }

public:
  tree(int val) { rootTree = new treeNode(val, nullptr, nullptr); };
  void add(int val) { add(rootTree, val); }
  treeNode *search(int target) { return search(rootTree, target); }
  bool del(int target) { return del(rootTree, target); }
};