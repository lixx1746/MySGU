#include <cstdio>

using namespace std;

int N, M;
int prev[105], used[105], G[105][105];

int main(void) {
  int from, to;
  scanf("%d%d", &N, &M);
  for(int i = 0; i < M; i++) {
    scanf("%d%d", &from, &to);
    if(G[from][to] == -1) { printf("No solution\n"); return 0; }
    G[from][to] = 1;
    G[to][from] = -1;
  }
  for(int i = 1; i <= N; i++) {
    int j;
    for(j = 1; j <= N; j++)
      if(!used[j]) {
        int flag = 0;
        for(int k = 1; k <= N; k++) if(!used[k] && G[j][k] < 0) { flag = 1; break; }
        if(!flag) break;
      }
    if(j > N) { printf("No solution\n"); return 0; }
    used[j] = 1;
    prev[j] = i;
  }


  for(int i = 1; i <= N; i++) {
    if(i != 1) printf(" ");
    printf("%d", prev[i]);
  }
  printf("\n");
  return 0;
}
