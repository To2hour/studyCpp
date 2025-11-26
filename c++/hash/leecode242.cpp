#include <iostream>
#include <math.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  bool isAnagram(string s, string t) {
    vector<int> a(26, 0);
    for (int i = 0; i < s.size(); i++) {
      a[s[i] - 'a']++;
    }
    for (int i = 0; i < t.size(); i++) {
      a[t[i] - 'a']--;
    }
    for (int i = 0; i < a.size(); i++) {
      if (a[i] != 0) {
        return false;
      }
    }
    return true;
  }
};

class Solution2 {
public:
  unordered_set<int> result_set;
  bool isHappy(int n) {
    if (n == 1) {
      return true;
    }
    if (result_set.count(n)) {
      return false;
    }
    result_set.insert(n);
    int nums = 0;
    while (n != 0) {
      nums += (n % 10) * (n % 10);
      n /= 10;
    }
    return isHappy(nums);
  }
};
class Solution3 {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> map;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
      int a = map.count(target - nums[i]);
      if (a == 0) {
        // map.insert(nums[i], i);
      } else {
        res.push_back(i);
        // res.push_back(map[]);
      }
    }
    return res;
  }
};
class Solution4 {
public:
  bool canConstruct(string ransomNote, string magazine) {
    vector<int> a(26, 0);
    for (char c : magazine) {
      a[c - 'a']++;
    }
    for (char c : ransomNote) {
      a[c - 'a']--;
    }
    for (int c : a) {
      if (c > 0) {
        return false;
      }
    }
    return true;
  }
};
//三数之和
class Solution5 {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    unordered_map<int, vector<vector<int>>> umap;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        umap[nums[i] + nums[j]].push_back({i, j});
      }
    }
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); i++) {
      if (umap.find(0 - nums[i]) != umap.end()) {
        vector<vector<int>> vec = umap[0 - nums[i]];
        for (auto v : vec) {
          if (v[0] == i || v[1] == i) {
            continue;
          }
          v.push_back(i);
          res.push_back(v);
        }
      }
    }
    return res;
  }
};
//反转单词
class Solution6 {
public:
  string reverseWords(string s) {
    string res;
    int i = 0;
    //去掉前面空格
    while (s[i] != ' ' && i <= s.size()) {
      if (i == s.size()) {
        return "";
      }
      i++;
    }
    int right = s.size() - 1;
    //去掉后面空格
    while (s[right] != ' ' && right <= s.size()) {
      right--;
    }
    while (i < right) {
      string temp;
      while (s[right] != ' ') {
        temp += s[right--];
      }
      reverseString(temp);
      res += temp;
      res += " ";
      while (s[right] == ' ') {
        right--;
      }
    }
    return res;
  }
  void reverseString(string &s) {
    for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
      swap(s[i], s[j]);
    }
  }
};
int main() {
  // Solution6 solution; // 创建类的实例
  // string result =
  //     solution.reverseWords("   hi,i am you   "); // 通过实例调用成员函数
  // cout << result << endl;
  cout << "啊的发掘绿卡的撒了" << endl;

}