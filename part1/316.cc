#include <cstdio>

using namespace std;

int points[7], scores[7];
int N, M;
int main(void) {
  scanf("%d %d", &N, &M);
  int from, to;
  for(int i = 1; i <= N; i++) points[i] = 100;
  for(int i = 0; i < M; i++) {
    scanf("%d %d", &from, &to);
    if(points[to] > 0) scores[from] += 3;
    points[to] -= 8;
  }
  for(int i = 1; i <= N; i++) {
    if(points[i] > 0) scores[i] += (points[i] / 2);
    printf("%d %d\n", points[i], scores[i]);
  }
  return 0;
}
