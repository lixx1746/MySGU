#include <cstdio>
#include <vector>
using namespace std;
int dp[16005], N, ans = -1010;
vector<int> G[16005];

void dfs(int v, int pre = -1) {
  for(int i = 0; i < (int) G[v].size(); i++) {
    int to = G[v][i];
    if(to != pre) {
      dfs(to, v);
      if(dp[to] > 0) dp[v] += dp[to];
    }
  }
  ans = max(ans, dp[v]);
}

int main(void) {
  scanf("%d", &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &dp[i]);
    ans = max(ans, dp[i]);
  }
  int from, to;
  for(int i = 1; i < N; i++) {
    scanf("%d %d", &from, &to);
    G[from].push_back(to);
    G[to].push_back(from);
  }
  dfs(1);
  printf("%d\n", ans);
  return 0;
}
