#include <algorithm>
#include <climits>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int left = 0;
    int right = 0;
    int length = INT_MAX;
    int sum = 0;
    while (right < nums.size()) {
      sum += nums[right];
      while (sum >= target) {
        length = min(length, right - left + 1);
        sum -= nums[left];
        left++;
      }
      right++;
    }
    if (length == INT_MAX) {
      return 0;
    } else {
      return length;
    }
  }
};
int main() {
  std::vector<int> nums = {2, 3, 1, 4, 2, 3};
  Solution sol; // 创建对象
  int a = sol.minSubArrayLen(7, nums);
  cout << a << endl;
}