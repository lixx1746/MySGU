#include <cstdio>

using namespace std;
int row[10005];
int N, M;
int main(void) {
  scanf("%d %d", &N, &M);
  int x, y;
  for(int i = 1; i <= M; i++) {
    scanf("%d %d", &x, &y);
    row[x]++; row[y]++;
  }
  int sum = 0;
  for(int i = 1; i <= N; i++) sum += row[i] * row[i];
  printf("%d\n", sum);
  return 0;
}
