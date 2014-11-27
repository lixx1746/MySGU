#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int max(int a, int b) { return a <= b ? b : a; }
const int MAX_V = 10005;

int fa[MAX_V], len[MAX_V];
int down[MAX_V], down_less[MAX_V], up[MAX_V], id[MAX_V];

int main(void) {
  int N, to, e;
  scanf("%d", &N);
  for(int i = 1; i < N; i++) {
    scanf("%d %d", &to, &e);
    fa[i] = to - 1;
    len[i] = e;
  }

  for(int i = N - 1; i > 0; i--) {
    if(down[fa[i]] < down[i] + len[i]) {
      down_less[fa[i]] = down[fa[i]];
      down[fa[i]] = down[i] + len[i];
      id[fa[i]] = i;
    }
    else if(down_less[fa[i]] < down[i] + len[i]) {
      down_less[fa[i]] = down[i] + len[i];
    }
  }

  for(int i = 1; i < N; i++)
    up[i] = max(up[fa[i]], i == id[fa[i]] ? down_less[fa[i]] : down[fa[i]]) + len[i];

  for(int i = 0; i < N; i++) cout << max(down[i], up[i]) << endl;

  return 0;
}
