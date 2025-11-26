#include <iostream>
#include <math.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
//反转单词
class Solution6 {
public:
  string reverseWords(string s) {
    string res;
    int i = 0;
    //去掉前面空格
    while (s[i] == ' ' && i <= s.size()) {
      if (i == s.size()) {
        return "";
      }
      i++;
    }
    int right = s.size() - 1;
    //去掉后面空格
    while (s[right] == ' ') {
      right--;
    }
    while (i < right) {
      string temp;
      while (s[right] != ' ' && right > 0) {
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
