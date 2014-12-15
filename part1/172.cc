#include <cstdio>
#include <cstring>
using namespace std;
int G[202][202];
int col[202];
int N, M, from, to, cnt;
int dfs(int v) {
  for(int t = 1; t <= N; t++) {
    if(!G[v][t]) continue;
    if(col[t] == -1) {
      col[t] = !col[v];
      cnt += col[t] == 0;
      if(!dfs(t)) return 0;
    }
    else if(col[v] == col[t]) return 0;
    }
  return 1;
}

int main(void) {
  scanf("%d %d", &N, &M);
  for(int i = 0; i < M; i++) {
    scanf("%d %d", &from, &to);
    G[from][to] = 1;
    G[to][from] = 1;
  }

  memset(col, -1, sizeof col);
  for(int i = 1; i <= N; i++) {
    if(col[i] != -1) continue;
    col[i] = 0;
    cnt++;
    if(!dfs(i)) { puts("no"); return 0; }
  }
  puts("yes");
  printf("%d\n", cnt);
  for(int i = 1; i <= N; i++) {
    if(!col[i]) printf("%d ", i);
  }

  return 0;
}
