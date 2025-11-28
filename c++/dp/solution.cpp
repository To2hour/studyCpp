#include <algorithm>
#include <climits>
#include <cstddef>
#include <iostream>
#include <math.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
//斐波那契
class Solution {
public:
  int fib(int n) {
    if (n <= 1) {
      return n;
    }
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      dp[i] = dp[i - 2] + dp[i - 1];
    }
    return dp[n];
  }
};