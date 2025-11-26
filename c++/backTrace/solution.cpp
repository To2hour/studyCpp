#include <algorithm>
#include <cstddef>
#include <iostream>
#include <math.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
// leecode 216. 组合总和 III
class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> temp(9, 1);
    vector<int> res;
    vector<vector<int>> rres;
    for (int i = 0; i < 9; i++) {
      temp[i] = i + 1;
    }
    auto dfs = [&](auto &&dfs, int value, int index) -> void {
      if (res.size() == k) {
        if (value == n) {
          rres.push_back(res);
        }
        return;
      }
      for (int i = index; i <= 8; i++) {
        if (value >= n) {
          continue;
        }
        value += temp[i];
        res.push_back(temp[i]);
        dfs(dfs, value, i + 1);
        value -= temp[i];
        res.pop_back();
      }
    };
    dfs(dfs, 0, 0);
    return rres;
  }
};
//
class Solution2 {
public:
  vector<vector<int>> res;
  vector<int> path;
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    auto dfs = [&](auto &&dfs, int &value, int index) -> void {
      if (target < value) {
        return;
      }
      if (target == value) {
        res.push_back(path);
      }
      for (int i = index; i < candidates.size(); i++) {
        if (i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) {

          continue;
        }
        path.push_back(candidates[i]);
        value += candidates[i];
        dfs(dfs, value, i);
        path.pop_back();
        value -= candidates[i];
      }
    };
    int value = 0;
    dfs(dfs, value, 0);
    return res;
  }
};

class Solution3 {
public:
  vector<vector<string>> res;
  vector<string> path;
  vector<vector<string>> partition(string s) {
    auto dfs = [&](auto &&dfs, int startIndex) -> void {
      if (startIndex == s.size()) {
        return;
      }
      for (int i = startIndex; i < s.size(); i++) {
        string temp = s.substr(startIndex, i - startIndex + 1);
        if (huiWen(temp)) {
          path.push_back(temp);
          dfs(dfs, i + 1);
          path.pop_back();
        }
      }
    };
  }
  bool huiWen(string s) {
    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
      if (s[left] != s[right]) {
        return false;
      }
      left++;
      right--;
    }
    return true;
  }
};