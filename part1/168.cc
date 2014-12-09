#include <cstdio>
#include <cstring>
using namespace std;

inline int min(int a, int b) { return a <= b ? a : b; }

int N, M;
int data[1001][1001], f[1005][1005];

int main(void) {
  scanf("%d %d", &N, &M);
  memset(f, 0x3F, sizeof f);
  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= M; j++)
      scanf("%d", &data[i][j]);


  for(int j = M; j >= 1; j--) {
    for(int i = N; i >= 1; i--) {
      f[i][j] = min(f[i][j], data[i][j]);
      f[i][j] = min(f[i][j], f[i + 1][j]);
      f[i][j] = min(f[i][j], f[i - 1][j + 1]);
      f[i][j] = min(f[i][j], f[i][j + 1]);
      f[i][j] = min(f[i][j], f[i + 1][j]);
    }
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      if(j > 1) printf(" ");
      printf("%d", f[i][j]);
    }
    printf("\n");
  }

  return 0;
}
