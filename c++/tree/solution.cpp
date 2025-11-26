#include <algorithm>
#include <cstddef>
#include <iostream>
#include <math.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
/**
Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};
 */
class Solution {
public:
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
  };
  int sumOfLeftLeaves(TreeNode *root) {
    auto dfs = [&](auto &&dfs, TreeNode *node, int &num) -> int {
      if (!node) {
        return num;
      }
      if (node->left != NULL && node->left->left == NULL &&
          node->left->right == NULL) {
        num += node->left->val;
      }
      dfs(dfs, node->right, num);
      dfs(dfs, node->left, num);
    };
    int res = 0;
    return dfs(dfs, root, res);
  };
  bool hasPathSum(TreeNode *root, int targetSum){
      auto dfs = [&](auto &&dfs, TreeNode *node, int res) -> bool {
        if (!node) {
          return false;
        }
        if (!node->left && !node->right) {
          res += node->val;
          if (res == targetSum) {
            return true;
          } else {
            return false;
          }
        }
        dfs(dfs, node->left, res + node->val);
        dfs(dfs, node->right, res + node->val);
      };
      return dfs(dfs, root,0);
    };
};