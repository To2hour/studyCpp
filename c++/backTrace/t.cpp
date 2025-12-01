#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> res;

  vector<string> allSubstrings(string s) {
    string path;
    dfs(s, 0, path);
    return res;
  }

  // dfs 枚举从 startIndex 开始的所有子串
  void dfs(const string &s, int startIndex, string path) {
    if (startIndex == s.size())
      return; // 到末尾就返回

    // 枚举以 startIndex 开头的所有长度子串
    for (int i = startIndex; i < s.size(); i++) {
      string temp = s.substr(startIndex, i - startIndex + 1);
      res.push_back(temp);          // 收集当前子串
      dfs(s, startIndex + 1, path); // 递归从下一个起点开始
    }
  }
};

int main() {
  auto dfs = [&](auto &&self, int &x) -> void {
    if (x >= 100)
      return;

    self(self, x); // 调用 operator()
    x += 1;
    cout << x << endl;
    
  };

  
}
