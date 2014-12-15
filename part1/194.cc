#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 205, INF=199999999;
int N, l[MAX_N][MAX_N], c[MAX_N][MAX_N], G[MAX_N][MAX_N], gap[MAX_N], d[MAX_N];
struct edge { int s, e; } e[MAX_N * MAX_N];
int sap(int u, int flow) {
  if(u == N + 1)
    return flow;
  int t, ans=0;
  for(int i = 1; i <= N + 1; ++i)
    if(G[u][i] && d[u] == d[i] + 1) {
      t = sap(i, min(flow - ans, G[u][i]));
      G[u][i] -= t, G[i][u] += t, ans += t;
      if(ans == flow)
        return ans;
    }
  if(d[0] <= N + 1) {
    if(!--gap[d[u]])
      d[0] = N + 2;
    ++gap[++d[u]];
  }
  return ans;
}

int main() {
  int m, i, j, k, t, t1, t2, sum = 0, ans = 0;
  scanf("%d%d",&N, &m);
  for(i = 1; i <= m; ++i) {
    scanf("%d%d%d%d", &j, &k, &t1, &t2);
    e[i]=(edge) { j, k };
    l[j][k]+=t1;
    c[j][k]+=t2;
  }
  for(i = 1; i <= N; ++i) {
    t = 0;
    for(j = 1; j <= N; ++j) {
      t += l[j][i] - l[i][j];
      G[i][j] = c[i][j] - l[i][j];
    }
    if(t > 0)
      sum += G[0][i] = t;
    else
      G[i][N+1] = -t;
  }
  for(gap[0] = N+2; d[0] <= N + 1;) ans += sap(0, INF);
  if(ans < sum) puts("NO");
  else {
    puts("YES");
    for(i = 1; i <= m; ++i)
      printf("%d\n",c[e[i].s][e[i].e] - G[e[i].s][e[i].e]);
  }
  return 0;
}
