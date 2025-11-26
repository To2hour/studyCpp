#include <algorithm>
#include <cstddef>
#include <iostream>
#include <math.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class MaxHeap {
public:
  vector<int> nums;
  /* 获取左子节点的索引 */
  int left(int i) { return 2 * i + 1; }

  /* 获取右子节点的索引 */
  int right(int i) { return 2 * i + 2; }

  /* 获取父节点的索引 */
  int parent(int i) {
    return (i - 1) / 2; // 向下整除
  }
  void push(int i) {
    nums.push_back(i);
    int index = nums.size() - 1;
    clean(index);
  }
  void clean(int index) {
    while (nums[index] > nums[parent(index)] && index > 0) {
      swap(nums[index], nums[parent(index)]);
      index = parent(index);
    }
  }
  void pop() {}
};