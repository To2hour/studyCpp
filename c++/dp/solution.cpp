#include <algorithm>
#include <climits>
#include <cstddef>
#include <iostream>
#include <iterator>
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
    //确认dp公式
    //确认dp中下标的含义
    //初始化dp
    //开始for
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      dp[i] = dp[i - 2] + dp[i - 1];
    }
    return dp[n];
  }
};
//爬楼梯
class Solution2 {
public:
  int climbStairs(int n) {
    if (n <= 2) {
      return n;
    }
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
};
//最小代价爬楼梯
class Solution3 {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    if (cost.size() <= 2) {
      return 0;
    }
    vector<int> dp(cost.size());
    dp[0] = cost[0];
    dp[1] = min(cost[0], cost[1]);
    for (int i = 2; i < cost.size(); i++) {
      dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }
    return min(dp[cost.size() - 1], dp[cost.size() - 2]);
  }
};
//走网格有多少路径
class Solution4 {
public:
  int uniquePaths(int m, int n) {
    if ((m <= 2 && n < 2) || (m < 2 && n <= 2)) {
      return 1;
    }
    // 格式：vector<vector<int>> 数组名(行数, vector<int>(列数, 初始值));
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1));
    for (int i = 2; i <= m; i++) {
      for (int j = 2; j <= n; j++) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[m][n];
  }
  //尝试1维数组
  int uniquePaths2(int m, int n) {
    if ((m <= 2 && n < 2) || (m < 2 && n <= 2)) {
      return 1;
    }
    // 格式：vector<vector<int>> 数组名(行数, vector<int>(列数, 初始值));
    vector<int> dp(m + 1, 1);
    for (int i = 2; i <= m; i++) {
      for (int j = 2; j <= n; j++) {
        dp[j] += dp[j - 1];
      }
    }
    return dp[m];
  }
};

class Solution5 {
public:
  //二维写法
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int rows = obstacleGrid.size();
    if (rows == 0)
      return 0;
    int cols = obstacleGrid[0].size();
    if (cols == 0)
      return 0;
    // 2. 初始化dp数组：rows行cols列，全0
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; i++) {
      if (obstacleGrid[i][0] == 1) {
        break;
      }
      dp[i][0] = 1;
    }
    for (int i = 0; i < cols; i++) {
      if (obstacleGrid[0][i] == 1) {
        break;
      }
      dp[0][i] = 1;
    }
    for (int i = 1; i < obstacleGrid.size(); i++) {
      for (int j = 1; j < obstacleGrid[i].size(); j++) {
        if (obstacleGrid[i][j] == 0) {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
      }
    }
    return dp[rows - 1][cols - 1];
  }
  //一维写法
  int uniquePathsWithObstacles2(vector<vector<int>> &obstacleGrid) {
    vector<int> dp(obstacleGrid[0].size(), 0);
    dp[0] = (obstacleGrid[0][0] == 0 ? 1 : 0);
    for (int i = 0; i < obstacleGrid.size(); i++) {
      for (int j = 0; j < obstacleGrid[i].size(); j++) {
        if (obstacleGrid[i][j] == 1) {
          dp[j] = 0;
        }
        if (j > 0 && obstacleGrid[i][j] == 0) {
          dp[j] += dp[j - 1];
        }
      }
    }
    return dp[dp.size() - 1];
  }
};
// 整数拆分
class Solution6 {
public:
  int integerBreak(int n) {
    if (n <= 3) {
      return n - 1;
    }
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    for (int i = 4; i <= n; i++) {
      for (int j = 2; j < i; j++) {
        cout << i << "个=" << dp[i] << endl;
        cout << j << "个=" << j * dp[i - j];
        dp[i] = max(dp[i], j * dp[i - j]);
      }
    }
    return dp[n];
  }
};