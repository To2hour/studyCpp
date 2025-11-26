#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main() {
  int a = 10;
  vector<int> vec = {1, 2, 3, 4, 5};
  vec.push_back(1);
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << endl;
  }
  auto dfs = [&](auto &&dfs, int x) {
    if (x == 0) {
      return 1;
    }
    return x * dfs(dfs, x - 1);
  };

  return 0;
}