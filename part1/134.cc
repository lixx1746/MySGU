#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N = 16005;
int N, ans;
int cnt[MAX_N], f[MAX_N];
vector<int> G[MAX_N];
void dfs(int v, int pre = -1) {
  cnt[v] = 1;
  f[v] = 0;
  for(int i = 0; i < (int) G[v].size(); i++) {
    int to = G[v][i];
    if(to != pre) {
      dfs(to, v);
      cnt[v] += cnt[to];
      f[v] = max(f[v], cnt[to]);
    }
  }
  f[v] = max(f[v], N - cnt[v]);
  ans = min(f[v], ans);
}

int main(void) {
  scanf("%d", &N);
  ans = N;
  int from, to;
  for(int i = 1; i < N; i++) {
    scanf("%d %d", &from, &to);
    if(from != to) {
    G[from].push_back(to);
    G[to].push_back(from);
    }
  }
  dfs(1);
  vector<int> res;
  for(int i = 1; i <= N; i++) {
    if(f[i] == ans) res.push_back(i);
  }
  printf("%d %d\n", ans, (int) res.size());
  for(int i = 0; i < (int) res.size(); i++) {
    if(i != 0) printf(" ");
    printf("%d", res[i]);
  }
  printf("\n");
  return 0;
}
