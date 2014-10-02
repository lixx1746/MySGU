#include <vector>
#include <cstdio>
#include <utility>
#include <cstdlib>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

vii g[7];
int ans[105], used[105];
int k, N;

void add_edge(int u, int v, int e) {
  g[u].push_back(make_pair(v, e));
  g[v].push_back(make_pair(u, -e));
}

void dfs(int node) {
  for(int i = 0; i < (int) g[node].size(); i++) {
    int to = g[node][i].first;
    int edge = g[node][i].second;
    if(!used[abs(edge)]) {
        used[abs(edge)] = 1;
        dfs(to);
        ans[k++] = edge;
      }
    }
}

int main(void) {
  scanf("%d", &N);
  int u, v;
  for(int i = 1; i <= N; i++) {
    scanf("%d %d", &u, &v);
    add_edge(u, v, i);
  }
  int count = 0, node = -1;
  for(int i = 0; i <= 6; i++) {
    if(node == -1 && g[i].size()) node = i;
    if(g[i].size() % 2) { count++; node = i; }
  }
  if(!(count == 0 || count == 2)) { puts("No solution"); return 0; }
  dfs(node);
  if (k != N) puts("No solution");
  else {
    for(int i = k - 1; i >= 0; i--) {
      int temp = ans[i];
      printf("%d %c\n", temp > 0 ? temp : -temp, temp > 0 ? '+' : '-');
    }
  }
  return 0;
}
